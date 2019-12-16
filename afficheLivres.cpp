#include <iostream>
#include <string>
#include <conio.h>

#include "biblio.h"
#include "color.h"
#include "controle.h"

#define KEY_LEFT      75
#define KEY_RIGHT     77
#define ESCAPE        27

using namespace std;

void afficheLivres(Bibliotheque biblio) {
    int listIndices[MAX_LIVRES];
    void afficheLivres(Bibliotheque biblio, int indiceLivres[], int nbrLivres);

    for (int i = 0; i < biblio.nbrLivres; i++) {
        listIndices[i] = i;
    }

    afficheLivres(biblio, listIndices, biblio.nbrLivres);
}

void afficheLivres(Bibliotheque biblio, int indiceLivres[], int nbrLivres) {
    int debut = 0, milieu = 0, fin = 0, touche;
    int afficheSomeLivres(Bibliotheque biblio, int indiceLivres[], int nbrLivres, int debut);

    // Rendre invisible le curseur
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);

    do {
        fin = afficheSomeLivres(biblio, indiceLivres, nbrLivres, milieu);

        do {
            touche = _getch();

            switch (touche) {
            case KEY_LEFT:
                if (milieu != 0) {
                    fin = milieu;
                    milieu = debut;
                } else {
                    touche = 0;
                }
                break;
            case KEY_RIGHT:
                if (fin != nbrLivres) {
                    debut = milieu;
                    milieu = fin;
                } else {
                    touche = 0;
                }
                break;
            case ESCAPE:
                break;
            default:
                break;
            }
        } while (touche != KEY_LEFT && touche != KEY_RIGHT && touche != ESCAPE);
    } while (touche != ESCAPE);

    // Rendre visible le curseur
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(out, &cursorInfo);
}

int afficheSomeLivres(Bibliotheque biblio, int indiceLivres[], int nbrLivres, int debut) {
    // void afficheLivre(Livre livre);
    system("cls");

    int taille_Titre;
    int taille_Auteur;
    int taille_Genre;
    int taille_Page;
    int taille_Date;
    int taille_restante;

    void separatorTab(COORD console);
    void getCoordCursor(COORD & position);
    void changeCoord(int x, int y);
    string createDate(Date date);

    COORD cursor;

    // Récupérer taille console...
    COORD console;
    CONSOLE_SCREEN_BUFFER_INFO coninfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
    console.X = coninfo.srWindow.Right + 1;
    console.Y = coninfo.srWindow.Bottom + 1;
    // Retirer 16 cases (espace et lignes)
    taille_restante = console.X - 16;
    // Calculer la taille de chaque colonne
    taille_Page = 6;
    taille_restante -= taille_Page;
    taille_Date = 10;
    taille_restante -= taille_Date;
    taille_Genre = 16;
    taille_restante -= taille_Genre;
    taille_Titre = taille_restante * 0.7;
    taille_restante -= taille_Titre;
    taille_Auteur = taille_restante;

    // On affiche l'entête du tableau...
    separatorTab(console);
    cout << "+ ";
    getCoordCursor(cursor);
    cout << "Titre";
    cursor.X += taille_Titre;
    changeCoord(cursor.X, cursor.Y);

    cout << " + ";
    getCoordCursor(cursor);
    cout << "Auteur(s)";
    cursor.X += taille_Auteur;
    changeCoord(cursor.X, cursor.Y);

    cout << " + ";
    getCoordCursor(cursor);
    cout << "Genre";
    cursor.X += taille_Genre;
    changeCoord(cursor.X, cursor.Y);

    cout << " + ";
    getCoordCursor(cursor);
    cout << "Pages";
    cursor.X += taille_Page;
    changeCoord(cursor.X, cursor.Y);

    cout << " + ";
    getCoordCursor(cursor);
    cout << "Date";
    cursor.X += taille_Date;
    changeCoord(cursor.X, cursor.Y);

    cout << " +" << endl;
    separatorTab(console);

    // On affiche les données du tableau
    bool place = true;
    int i = debut;
    while (i < nbrLivres && place) {
        Livre livre;
        livre = biblio.tab_livres[indiceLivres[i]];

        getCoordCursor(cursor);
        for (int i = livre.nbrAuteurs - 1; i >= 0; i--) {
            changeCoord(cursor.X, cursor.Y + i);
            cout << "+ ";
        }
        // Le titre
        getCoordCursor(cursor);
        if (livre.titre.length() > taille_Titre) {
            for (int i = 0; i < taille_Titre - 3; i++) {
                cout << livre.titre[i];
            }
            cout << "...";
        } else {
            cout << livre.titre;
            cursor.X += taille_Titre;
            changeCoord(cursor.X, cursor.Y);
        }
        for (int i = livre.nbrAuteurs - 1; i >= 0; i--) {
            changeCoord(cursor.X, cursor.Y + i);
            cout << " + ";
        }


        // Les auteurs
        getCoordCursor(cursor);
        for (int i = 0; i < livre.nbrAuteurs; i++) {
            changeCoord(cursor.X, cursor.Y + i);
            cout << biblio.tab_auteurs[livre.ListeAuteurs[i]].prenom << " " << biblio.tab_auteurs[livre.ListeAuteurs[i]].nom;
        }
        cursor.X += taille_Auteur;
        changeCoord(cursor.X, cursor.Y);
        for (int i = livre.nbrAuteurs - 1; i >= 0; i--) {
            changeCoord(cursor.X, cursor.Y + i);
            cout << " + ";
        }

        // Le genre
        getCoordCursor(cursor);
        if (livre.genre.length() > taille_Genre) {
            for (int i = 0; i < taille_Genre - 3; i++) {
                cout << livre.genre[i];
            }
            cout << "...";
        } else {
            cout << livre.genre;
            cursor.X += taille_Genre;
            changeCoord(cursor.X, cursor.Y);
        }
        for (int i = livre.nbrAuteurs - 1; i >= 0; i--) {
            changeCoord(cursor.X, cursor.Y + i);
            cout << " + ";
        }

        // Les pages
        getCoordCursor(cursor);
        if (livre.pages > 999999) {
            string pages;
            pages = convertInt2String(livre.pages);
            for (int i = 0; i < taille_Page - 3; i++) {
                cout << pages[i];
            }
            cout << "...";
        } else {
            cout << livre.pages;
            cursor.X += taille_Page;
            changeCoord(cursor.X, cursor.Y);
        }
        for (int i = livre.nbrAuteurs - 1; i >= 0; i--) {
            changeCoord(cursor.X, cursor.Y + i);
            cout << " + ";
        }

        // La date
        getCoordCursor(cursor);
        cout << createDate(livre.date);
        cursor.X += taille_Date;
        changeCoord(cursor.X, cursor.Y);
        for (int i = 0; i < livre.nbrAuteurs; i++) {
            changeCoord(cursor.X, cursor.Y + i);
            cout << " +";
        }
        cout << endl;
        separatorTab(console);

        // Calcul de la place
        getCoordCursor(cursor);
        if ((i + 1) < nbrLivres && cursor.Y < console.Y - (biblio.tab_livres[indiceLivres[i + 1]].nbrAuteurs + 1)) {
            // PLACE
        } else {
            if (debut != 0) {
                changeCoord(0, console.Y - 1); // On le met à la fin, pk pas juste après le tableau
                cout << "<-";
            }
            if ((i + 1) < nbrLivres) {
                changeCoord(console.X - 2, console.Y - 1); // On le met à la fin, pk pas juste après le tableau
                cout << "->";
            }
            place = false;
        }

        i++;
    }

    return i;
}

void separatorTab(COORD console) {
    // On affiche le haut du tableau
    for (int i = 0; i < console.X; i++) {
        cout << "+";
    }
    cout << endl;
}

void getCoordCursor(COORD& position) {
    CONSOLE_SCREEN_BUFFER_INFO coninfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
    position.X = coninfo.dwCursorPosition.X;
    position.Y = coninfo.dwCursorPosition.Y;
}

string createDate(Date date) {
    string dateS;

    dateS = convertInt2String(date.jour) + "/" + convertInt2String(date.mois) + "/" + convertInt2String(date.annee);

    return dateS;
}