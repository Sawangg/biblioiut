#include <iostream>
#include <string>
using namespace std;

string verifDate(int a, int m, int j) {
    string erreur;


    if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (j == 31) {
            erreur = "Le mois que vous avez choisi ne contient pas 31 jours ! La date est invalide\n";
        } else {
            erreur = "";
        }
    } else {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            erreur = "";
        } else {
            if ((j == 29) && (a % 4 == 0) && (a / 100 != 0)) {
                erreur = "";
            } else {
                if (j < 29) {
                    erreur = "";
                } else {
                    erreur = "Le mois que vous avez choisi ne contient pas 29 jours car l'annee n'est pas bissextile\n";
                }
            }
        }
    }
    return erreur;
}