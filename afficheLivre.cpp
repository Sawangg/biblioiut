#include <iostream>
/*#include <string>

#include "biblio.h"
#include "controle.h"
#include "color.h"

using namespace std;

void afficheLivre(Livre livre) {
    int taille_Titre;
    int taille_Auteur;
    int taille_Genre;
    int taille_Page;
    int taille_Date;
    int taille_restante;

    void separatorTab(COORD console);

    cout << "\n";
    cout << "Titre : " << livre.titre << endl;
    cout << "Auteur : " << livre.auteur << endl;
    cout << "Date : " << livre.date.jour << "/" << livre.date.mois << "/" << livre.date.annee << endl;
    cout << "Pages : " << livre.pages << endl;


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
    taille_Titre = console.X * 0.3;
    taille_restante -= taille_Titre;
    taille_Auteur = taille_restante;

    separatorTab(console);
    // On affiche le contenu
    cout << "+ ";
    cout << "Titre";
    for (int i = 0; i < taille_Titre - 5; i++) {
        cout << " ";
    }
    cout << " + ";
    cout << "Auteur(s)";
    for (int i = 0; i < taille_Auteur - 9; i++) {
        cout << " ";
    }
    cout << " + ";
    cout << "Genre";
    for (int i = 0; i < taille_Genre - 5; i++) {
        cout << " ";
    }
    cout << " + ";
    cout << "Pages";
    for (int i = 0; i < taille_Page - 5; i++) {
        cout << " ";
    }
    cout << " + ";
    cout << "Date";
    for (int i = 0; i < taille_Date - 4; i++) {
        cout << " ";
    }
    cout << " +" << endl;
    separatorTab(console);

    cout << "+ ";
    if (livre.titre.length() > taille_Titre) {
        cout << "ERROR";
        for (int i = 0; i < taille_Titre - 5; i++) {
            cout << " ";
        }
    } else {
        cout << livre.titre;
        for (int i = 0; i < taille_Titre - livre.titre.length(); i++) {
            cout << " ";
        }
    }
    cout << " + ";
    cout << "ERROR";
    for (int i = 0; i < taille_Auteur - 5; i++) {
        cout << " ";
    }
    cout << " + ";
    if (livre.genre.length() > taille_Genre) {
        cout << "ERROR";
        for (int i = 0; i < taille_Genre - 5; i++) {
            cout << " ";
        }
    } else {
        cout << livre.genre;
        for (int i = 0; i < taille_Genre - livre.genre.length(); i++) {
            cout << " ";
        }
    }
    cout << " + ";
    if (livre.pages > 999999) {
        cout << "ERROR";
        for (int i = 0; i < taille_Page - 5; i++) {
            cout << " ";
        }
    } else {
        cout << livre.pages;
        for (int i = 0; i < 5; i++) {
            cout << " ";
        }
    }
    cout << " + ";
    cout << "ERROR";
    for (int i = 0; i < taille_Date - 5; i++) {
        cout << " ";
    }
    cout << " +" << endl;
    separatorTab(console);
}

void separatorTab(COORD console) {
    // On affiche le haut du tableau
    for (int i = 0; i < console.X; i++) {
        cout << "+";
    }
    cout << endl;
}*/