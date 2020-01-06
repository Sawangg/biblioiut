#include <iostream>
#include <sstream>
#include <string>

#include "Utilitaire.h"
using namespace std;


///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de controler que la saisie est bien un entier
//////
//////        ENTREES : RIEN
//////        SORTIES : entier
//////
///////////////////////////////////////////////////////////////
int ControleEntier() {
    string theInput = "";
    int inputAsInt;
    bool successful = false;

    while (theInput == "") {
        getline(cin, theInput);
    }
    theInput = removeAllspace(theInput);
    stringstream ss(theInput);
    ss >> inputAsInt;
    successful = !ss.fail();

    while (cin.fail() || cin.eof() || theInput.find_first_not_of("0123456789") != string::npos || !successful) {
        cout << "\x1B[31mMerci de rentrer un entier positif compris entre 0 et 2147483647 (inclus) !\033[0m" << endl;

        if (theInput.find_first_not_of("0123456789") == string::npos) {
            cin.clear();
        }

        getline(cin, theInput);
        while (theInput == "") {
            getline(cin, theInput);
        }
        stringstream ss(theInput);
        ss >> inputAsInt;
        successful = !ss.fail();
    }

    string::size_type st;
    inputAsInt = stoi(theInput, &st);
    return inputAsInt;
}


///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de vérifier le format de la date
//////
//////        ENTREES : entieer, entier, entier
//////        SORTIES : chaîne
//////
//////        Retourne une chaîne vide si pas d'erreur dans la date sinon retourne le message d'erreur
//////
///////////////////////////////////////////////////////////////
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


///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de remplacer les tabulations par des espaces
//////
//////        ENTREES : chaine
//////        SORTIES : chaine
//////
///////////////////////////////////////////////////////////////
string removeTabulation(string text) {
    string newText = "";

    for (int i = 0; i < text.length(); i++) {
        if (text[i] != '\t') {
            newText += text[i];
        } else {
            newText += " ";
        }
    }

    return newText;
}
///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de supprimer les doubles espaces
//////
//////        ENTREES : chaine
//////        SORTIES : chaine
//////
///////////////////////////////////////////////////////////////
string removeDoubleSpace(string text) {
    string newText = "";

    int i = 0;
    while (text[i] != '\0') {
        if (!(text[i] == ' ' && text[i + 1] == ' ')) {
            newText += text[i];
        }
        i++;
    }

    return newText;
}
///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de supprimer l'espace au début
//////
//////        ENTREES : chaine
//////        SORTIES : chaine
//////
///////////////////////////////////////////////////////////////
string removeBeginSpace(string text) {
    string newText = "";

    if (text[0] == ' ') {
        for (int i = 1; i < text.length(); i++) {
            newText += text[i];
        }
    } else {
        newText = text;
    }

    return newText;
}
///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de supprimer l'espace à la fin
//////
//////        ENTREES : chaine
//////        SORTIES : chaine
//////
///////////////////////////////////////////////////////////////
string removeEndSpace(string text) {
    string newText = "";

    if (text.length() >= 1) {
        if (text[text.length() - 1] == ' ') {
            for (int i = 0; i < text.length() - 1; i++) {
                newText += text[i];
            }
        } else {
            newText = text;
        }
    }

    return newText;
}
///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de supprimer tout les espaces indésirables
//////
//////        ENTREES : chaine
//////        SORTIES : chaine
//////
///////////////////////////////////////////////////////////////
string removeAllIndesirableSpace(string text) {
    text = removeTabulation(text);
    text = removeDoubleSpace(text);
    text = removeBeginSpace(text);
    text = removeEndSpace(text);

    return text;
}
///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de supprimer tout les espaces
//////
//////        ENTREES : chaine
//////        SORTIES : chaine
//////
///////////////////////////////////////////////////////////////
string removeAllspace(string text) {
    string newText = "";

    text = removeAllIndesirableSpace(text);

    int i = 0;
    while (text[i] != '\0') {
        if (text[i] != ' ') {
            newText += text[i];
        }
        i++;
    }

    return newText;
}

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de récupérer la date inférieur entre les deux
//////
//////        ENTREES : date, date
//////        SORTIES : date
//////
///////////////////////////////////////////////////////////////
Date getDateInf(Date date1, Date date2) {
    if (date1.jour == -1) {
        return date2;
    }
    if (date2.jour == -1) {
        return date1;
    }

    if (date1.annee == date2.annee) {
        if (date1.mois == date2.mois) {
            if (date1.jour < date2.jour) {
                return date1;
            } else {
                return date2;
            }
        } else {
            if (date1.mois < date2.mois) {
                return date1;
            } else {
                return date2;
            }
        }
    } else {
        if (date1.annee < date2.annee) {
            return date1;
        } else {
            return date2;
        }
    }
}
///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de récupérer la date supérieur entre les deux
//////
//////        ENTREES : date, date
//////        SORTIES : date
//////
///////////////////////////////////////////////////////////////
Date getDateSup(Date date1, Date date2) {
    if (date1.jour == -1) {
        return date2;
    }
    if (date2.jour == -1) {
        return date1;
    }

    if (date1.annee == date2.annee) {
        if (date1.mois == date2.mois) {
            if (date1.jour < date2.jour) {
                return date2;
            } else {
                return date1;
            }
        } else {
            if (date1.mois < date2.mois) {
                return date2;
            } else {
                return date1;
            }
        }
    } else {
        if (date1.annee < date2.annee) {
            return date2;
        } else {
            return date1;
        }
    }
}
///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de vérifier si une date est comprise entre deux autres
//////
//////        ENTREES : date, date, date
//////        SORTIES : chaine
//////
///////////////////////////////////////////////////////////////
string verifIntervalleDate(Date dateInf, Date date, Date dateSup) {
    bool erreur;
    string error;

    // On compare la date à la dateInf
    if (dateInf.jour != -1) {
        if (dateInf.annee == date.annee) {
            if (dateInf.mois == date.mois) {
                if (dateInf.jour == date.jour) {
                    erreur = false;
                } else {
                    if (dateInf.jour > date.jour) {
                        erreur = true;
                    } else {
                        erreur = false;
                    }
                }
            } else {
                if (dateInf.mois > date.mois) {
                    erreur = true;
                } else {
                    erreur = false;
                }
            }
        } else {
            if (dateInf.annee > date.annee) {
                erreur = true;
            } else {
                erreur = false;
            }
        }
    } else {
        erreur = false;
    }

    // On compare à la dateSup
    if (!erreur) {
        if (dateSup.jour != -1) {
            if (dateSup.annee == date.annee) {
                if (dateSup.mois == date.mois) {
                    if (dateSup.jour == date.jour) {
                        erreur = false;
                    } else {
                        if (dateSup.jour < date.jour) {
                            erreur = true;
                        } else {
                            erreur = false;
                        }
                    }
                } else {
                    if (dateSup.mois < date.mois) {
                        erreur = true;
                    } else {
                        erreur = false;
                    }
                }
            } else {
                if (dateSup.annee < date.annee) {
                    erreur = true;
                } else {
                    erreur = false;
                }
            }
        } else {
            erreur = false;
        }
    }

    if (erreur) {
        error = "La date n'est pas valide, elle doit être ";
        if (dateInf.jour != -1 && dateSup.jour != -1) {
            error += "comprise entre " + convertDate2String(dateInf) + " et " + convertDate2String(dateSup) + "\n";
        } else {
            if (dateInf.jour == -1) {
                error += "inférieur à " + convertDate2String(dateSup) + "\n";
            } else {
                error += "supérieur à " + convertDate2String(dateInf) + "\n";
            }
        }
    }

    return error;
}