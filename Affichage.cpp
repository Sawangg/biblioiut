#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

#include "Header.h"

using namespace std;

void afficheLivres(Bibliotheque& biblio) {
    Liste<int> livres;

    creationListeLivresBibliotheque(biblio, livres);
    afficheLivres(biblio, livres);
}
void creationListeLivresBibliotheque(Bibliotheque biblio, Liste<int>& livres) {
    livres.nbElements = 0;

    for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
        livres.ListeElements[i] = i;
    }
    livres.nbElements = biblio.bibliothequeLivre.nbElements;
}

void afficheLivres(Bibliotheque& biblio, Liste<int> livres) {
    int debut = 0, milieu = 0, fin = 0, touche, numPage = 1;
    int newselection = 0, oldselection = 0;

    // Récupérer taille console...
    COORD console = getTailleConsole();

    // Retirer 16 cases (espace et séparations)
    int taille_restante = console.X - 16;
    // On détermine la taille de chaque colonne pour le livre
    int taille_Page = 6;
    taille_restante -= taille_Page;
    int taille_Date = 10;
    taille_restante -= taille_Date;
    int taille_Genre = 16;
    taille_restante -= taille_Genre;
    int taille_Titre = taille_restante * 0.7;
    taille_restante -= taille_Titre;
    int taille_Auteur = taille_restante;

    Liste<int> coordXColonne;
    coordXColonne.ListeElements[0] = 2;
    coordXColonne.ListeElements[1] = 2 + taille_Titre + 3;
    coordXColonne.ListeElements[2] = 2 + taille_Titre + 3 + taille_Auteur + 3;
    coordXColonne.ListeElements[3] = 2 + taille_Titre + 3 + taille_Auteur + 3 + taille_Genre + 3;
    coordXColonne.ListeElements[4] = 2 + taille_Titre + 3 + taille_Auteur + 3 + taille_Genre + 3 + taille_Page + 3;
    coordXColonne.nbElements = 5;
    Liste<int> coordXSeparation;
    coordXSeparation.ListeElements[0] = 0;
    coordXSeparation.ListeElements[1] = 2 + taille_Titre;
    coordXSeparation.ListeElements[2] = 2 + taille_Titre + 3 + taille_Auteur;
    coordXSeparation.ListeElements[3] = 2 + taille_Titre + 3 + taille_Auteur + 3 + taille_Genre;
    coordXSeparation.ListeElements[4] = 2 + taille_Titre + 3 + taille_Auteur + 3 + taille_Genre + 3 + taille_Page;
    coordXSeparation.ListeElements[5] = 2 + taille_Titre + 3 + taille_Auteur + 3 + taille_Genre + 3 + taille_Page + 3 + taille_Date;
    coordXSeparation.nbElements = 6;

    // Rendre invisible le curseur
    cursorVisible(false);

    do {
        if (fin == milieu) {
            // Passer à la page suivante
            fin = creationTableauLivre(coordXColonne, coordXSeparation, biblio, livres, milieu, numPage);
            newselection = milieu;
        } else {
            // Passer à la page précédente
            fin = creationTableauLivre(coordXColonne, coordXSeparation, biblio, livres, milieu, numPage);
            newselection = fin - 1;
        }

        do {
            underlineSelection(coordXColonne, coordXSeparation, biblio, livres.ListeElements, newselection, milieu);
            touche = _getch();

            switch (touche) {
            case KEY_LEFT:
                if (milieu != 0) {
                    fin = milieu;
                    milieu = debut;
                    numPage--;

                    // Changer selection
                    oldselection = newselection;
                    removeUnderlineOldSelection(coordXColonne, coordXSeparation, biblio, livres.ListeElements, oldselection, milieu);
                    newselection = milieu;
                } else {
                    touche = 0;
                }
                break;
            case KEY_RIGHT:
                if (fin != livres.nbElements) {
                    debut = milieu;
                    milieu = fin;
                    numPage++;

                    // Changer selection
                    oldselection = newselection;
                    removeUnderlineOldSelection(coordXColonne, coordXSeparation, biblio, livres.ListeElements, oldselection, milieu);
                    newselection = milieu;
                } else {
                    touche = 0;
                }
                break;
            case KEY_DOWN:
                if (newselection == fin - 1) {
                    if (fin != livres.nbElements) {
                        debut = milieu;
                        milieu = fin;
                        numPage++;

                        // Changer selection
                        oldselection = newselection;
                        removeUnderlineOldSelection(coordXColonne, coordXSeparation, biblio, livres.ListeElements, oldselection, milieu);
                        newselection = milieu;
                    }
                } else {
                    oldselection = newselection;
                    removeUnderlineOldSelection(coordXColonne, coordXSeparation, biblio, livres.ListeElements, oldselection, milieu);
                    newselection++;
                }
                break;
            case KEY_UP:
                if (newselection == milieu) {
                    if (milieu != 0) {
                        fin = milieu;
                        milieu = debut;
                        numPage--;

                        // Changer selection
                        oldselection = newselection;
                        removeUnderlineOldSelection(coordXColonne, coordXSeparation, biblio, livres.ListeElements, oldselection, milieu);
                        newselection = milieu;
                    }
                } else {
                    oldselection = newselection;
                    removeUnderlineOldSelection(coordXColonne, coordXSeparation, biblio, livres.ListeElements, oldselection, milieu);
                    newselection--;
                }
                break;
            case ESCAPE:
                break;
            case ENTER:
                ModificationLivre(biblio, livres, newselection);
                break;
            default:
                break;
            }
        } while (touche != KEY_LEFT && touche != KEY_RIGHT && touche != ESCAPE && touche != ENTER);
    } while (touche != ESCAPE && livres.nbElements != 0);

    // Rendre visible le curseur
    cursorVisible(true);
}

// Amélioration : Fusion des deux fonctions...
void removeUnderlineOldSelection(Liste<int> coordXColonne, Liste<int> coordXSeparation, Bibliotheque biblio, int indiceLivres[], int oldSelection, int debut) {
    Livre livre;
    COORD cursor;
    int Y;

    // Récupérer position du livre
    Y = getPositionLivreTableau(biblio, indiceLivres, debut, oldSelection);
    // Changer l'écriture (blanc sur noir)
    SetColorAndBackground(15, 0);
    // On écrit les données
    livre = biblio.bibliothequeLivre.ListeElements[indiceLivres[oldSelection]];
    getCoordCursor(cursor);
    cursor.Y = Y;
    affichageDonneesColonnes(coordXColonne, coordXSeparation, cursor, biblio, livre);
}
void underlineSelection(Liste<int> coordXColonne, Liste<int> coordXSeparation, Bibliotheque biblio, int indiceLivres[], int newSelection, int debut) {
    Livre livre;
    COORD cursor;
    int Y;

    // Récupérer position du livre
    Y = getPositionLivreTableau(biblio, indiceLivres, debut, newSelection);
    // Changer l'écriture (noir sur blanc)
    SetColorAndBackground(0, 15);
    // On écrit les données
    livre = biblio.bibliothequeLivre.ListeElements[indiceLivres[newSelection]];
    getCoordCursor(cursor);
    cursor.Y = Y;
    affichageDonneesColonnes(coordXColonne, coordXSeparation, cursor, biblio, livre);
    // Remettre en normal
    SetColorAndBackground(15, 0);
}

int getPositionLivreTableau(Bibliotheque biblio, int indiceLivres[], int debut, int indiceSelection) {
    int i = debut, y = 3;

    while (i != indiceSelection) {
        y += biblio.bibliothequeLivre.ListeElements[i].auteursLivre.nbElements + 1;
        i++;
    }

    return y;
}

void affichageSeparationsColonnes(Liste<int> coordXSeparation, COORD cursor, Livre livre) {
    for (int i = 0; i < coordXSeparation.nbElements; i++) {
        for (int z = 0; z < livre.auteursLivre.nbElements; z++) {
            if (i == 0) {
                changeCoord(coordXSeparation.ListeElements[i], cursor.Y + z);
                cout << cyan << "| ";
            } else if (i == coordXSeparation.nbElements - 1) {
                changeCoord(coordXSeparation.ListeElements[i], cursor.Y + z);
                cout << cyan << " |";
            } else {
                changeCoord(coordXSeparation.ListeElements[i], cursor.Y + z);
                cout << cyan << " | ";
            }
        }
    }
}

void affichageDonneesColonnes(Liste<int> coordXColonne, Liste<int> coordXSeparation, COORD cursor, Bibliotheque biblio, Livre livre) {
    for (int i = 0; i < coordXColonne.nbElements; i++) {
        changeCoord(coordXColonne.ListeElements[i], cursor.Y);
        int taille = coordXSeparation.ListeElements[i + 1] - coordXColonne.ListeElements[i];

        switch (i) {
        case 0:
            afficheStringInTableau(livre.titre, taille);
            break;
        case 1:
            for (int z = 0; z < livre.auteursLivre.nbElements; z++) {
                changeCoord(coordXColonne.ListeElements[i], cursor.Y + z);
                afficheStringInTableau(biblio.bibliothequeAuteur.ListeElements[livre.auteursLivre.ListeElements[z]].prenom + " " + biblio.bibliothequeAuteur.ListeElements[livre.auteursLivre.ListeElements[z]].nom, taille);
            }
            break;
        case 2:
            afficheStringInTableau(livre.genre, taille);
            break;
        case 3:
            afficheStringInTableau(convertInt2String(livre.pages), taille);
            break;
        case 4:
            afficheStringInTableau(convertDate2String(livre.date), taille);
            break;
        default:
            break;
        }
    }
}

int creationTableauLivre(Liste<int> coordXColonne, Liste<int> coordXSeparation, Bibliotheque biblio, Liste<int> livres, int debut, int numPage) {
    // On affiche l'entête du tableau...
    system("cls");
    separatorTab();
    enteteTab(coordXColonne, coordXSeparation);
    separatorTab();

    // On affiche les données du tableau
    bool place = true;
    int i = debut;
    while (i < livres.nbElements && place) {
        Livre livre;
        livre = biblio.bibliothequeLivre.ListeElements[livres.ListeElements[i]];

        COORD cursor;
        getCoordCursor(cursor);
        
        affichageDonneesColonnes(coordXColonne, coordXSeparation, cursor, biblio, livre);
        affichageSeparationsColonnes(coordXSeparation, cursor, livre);

        cout << endl;
        separatorTab();

        // Vérification de la place disponible...
        getCoordCursor(cursor);
        if ((i + 1) < livres.nbElements && cursor.Y < getTailleConsole().Y - (biblio.bibliothequeLivre.ListeElements[livres.ListeElements[i + 1]].auteursLivre.nbElements + 1)) {
            // PLACE
        } else {
            if (debut != 0) {
                changeCoord(0, getTailleConsole().Y - 1); // On le met à la fin, pk pas juste après le tableau
                cout << yellow << "<-" << normal;
            }
            // Afficher numéro Page
            changeCoord((getTailleConsole().X / 2) - (6 / 2), getTailleConsole().Y - 1);
            cout << yellow << "Page " << numPage << normal;
            if ((i + 1) < livres.nbElements) {
                changeCoord(getTailleConsole().X - 2, getTailleConsole().Y - 1); // On le met à la fin, pk pas juste après le tableau
                cout << yellow << "->" << normal;
            }
            place = false;
        }

        i++;
    }

    return i;
}

void afficheStringInTableau(string donnee, int taille) {
    if (donnee.length() > taille) {
        for (int i = 0; i < taille - 3; i++) {
            cout << donnee[i];
        }
        cout << "...";
    } else {
        cout << donnee;
        for (int i = donnee.length(); i < taille; i++) {
            cout << " ";
        }
    }
}

void separatorTab() {
    // On affiche le haut du tableau
    cout << cyan << "+";
    for (int i = 0; i < getTailleConsole().X - 2; i++) {
        cout << "-";
    }
    cout << "+";
    cout << normal << endl;
}

void enteteTab(Liste<int> coordXColonne, Liste<int> coordXSeparation) {
    COORD cursor;
    Livre imaginaire;
    imaginaire.auteursLivre.nbElements = 1;

    getCoordCursor(cursor);
    for (int i = 0; i < coordXColonne.nbElements; i++) {
        changeCoord(coordXColonne.ListeElements[i], cursor.Y);

        switch (i) {
        case 0:
            cout << "Titre";
            break;
        case 1:
            cout << "Auteur(s)";
            break;
        case 2:
            cout << "Genre";
            break;
        case 3:
            cout << "Pages";
            break;
        case 4:
            cout << "Date";
            break;
        default:
            break;
        }
    }
    affichageSeparationsColonnes(coordXSeparation, cursor, imaginaire);
}