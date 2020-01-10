# Bibliothèque

**Header**
Tout ce qu'il y a dessous est déclaré dans toutes les fonctions et les procédures du programme.
```
Avec type Date = {
	jour : entier
	mois : entier
	annee : entier
}
Avec type Auteur = {
	nom : chaîne
	prenom : chaîne
	LivresAuteurs[MAX] : entiers
	nbrLivresAuteurs : entier
	dateN : Date
	dateM : Date
}
Avec type Livre = {
	titre : chaîne
	genre : chaîne
	date : Date
	pages : entier
	AuteursLivres[MAX] : entiers
	nbrAuteursLivres : entier
}
Avec type Bibliotheque = {
	Livres[MAX] : Livre
	nbrLivres : entier
	Auteurs[MAX] : Auteur
	nbrAuteurs : entier
}
Avec type Contrainte = {
	contrainte1 : chaîne
	positionContrainte1: entier
	operateur : chaîne
	contrainte1 : chaîne
	positionContrainte1: entier
}

CONSTANTE GENRES[19] <- { "Roman", "Manga", "Bande dessinée", "Poésie", "Fable", "Science-fiction", "Fantaisie", "Fantastique", "Horreur", "Biographie", "Conte", "Epopée", "Nouvelle", "Article", "Pièce de théâtre", "Lettre", "Essai", "Policier", "Autre" }
CONSTANTE MAX = 100
```
****
**Programme**
```
Programme Bibliothèque
Début
	Avec selection : entier
		biblio : Bibliotheque
		contraintes[] : Contrainte
		nbrContraintes : entier
		
	biblio.nbrLivres = 0
	biblio.nbrAuteurs = 0
	nbrContraintes = 0

	répéter
		selection = MenuGeneral("Afficher l'ensemble des livres de la bibliothèque\nAjouter un nouveau livre\nModifier un livre\nModifier un auteur\nRechercher un livre\nSauvegarder la bibliothèque\nQuitter",7)
		Selon (selection) faire
			Cas 1:
				Si (biblio.nbrLivres > 0) alors
					AffichageLivres(biblio;)
				Sinon
					Afficher "IL n'y a pas de livres à afficher..."
				finSi
			Cas 2:
				Si (biblio.nbrLivres < MAX) alors
					AjoutLivres(;biblio)
				Sinon
					Afficher "La limite de nombres de livres a été atteinte"
				finSi
			Cas 3:
				Si (biblio.nbrAuteurs > 0) alors
					ModificationLivre(;biblio)
				Sinon
					Afficher "Il n'y a pas d'auteurs enregistrés dans la bibliothèque"
				finSi
			Cas 4:
				Si (biblio.nbrAuteurs > 0) alors
					ModificationAuteur(;biblio)
				Sinon
					Afficher "Il n'y a pas d'auteurs enregistrés dans la bibliothèque"
				finSi
			Cas 5:
				Si (biblio.nbrLivres > 0) alors
					Recherche(;biblio)
				Sinon
					Afficher "IL n'y a pas de livres dans la bibliothèque..."
				finSi
			Cas 6:
				Si (biblio.nbrLivres > 0) alors
					sauvegardeBibliotheque(;biblio)
				Sinon
					Afficher "IL n'y a pas de livres dans la bibliothèque..."
				finSi
			Cas 7:
				Afficher "En revoir..."
			Defaut:
				Afficher "Erreur inconnue dans le choix du menu sur le MAIN !"
		finFaire
	Tant que (selection != 7)
Fin Bibliothèque
```
****
**Fonctions et Procédures**
```
Fonctions MenuGeneral(options : chaîne, nbOptions : entier) retourne entier
Début
	Avec choix : entier

	Afficher options
	Afficher "Quel est votre choix ?"
	Saisir choix
	Tant que (choix <= 0 ou choix > nbOptions) faire
		Afficher "Choix incorrect, il doit être compris entre 1 et ", nbOptions
		Afficher "Quel est votre choix ?"
		Saisir choix
	finFaire

	retourne choix
Fin 
```

```
Procédure AfficheLivres(biblio : Bibliotheque;)
Début
	Avec indicesLivres[] : entier
		nbrIndicesLivres : entier
	
	creationListeIndicesLivresBibliotheque(biblio ; indicesLivres, nbrIndicesLivres)
	AffichesLivres(biblio, indicesLivres, nbrIndicesLivres)
Fin 
```
```
Procédure creationListeIndicesLivresBibliotheque(biblio : Bibliotheque ; indicesLivres[] : entier, nbrIndicesLivres : entier)
Début
	nbrIndicesLivres <- 0
	
	Pour i de 0 à (biblio.nbrLivres - 1) faire
		indicesLivres[nbrIndicesLivres] <- i
		nbrIndicesLivres <- nbrIndicesLivres + 1
	finFaire
Fin 
```
```
Procédure AfficheLivres(biblio : Bibliotheque, indicesLivres[] : entier, nbrIndicesLivres : entier;)
Début
	Pour i de 0 à (nbrIndicesLivres - 1) faire
		Afficher biblio.Livres[i].titre, " de ", biblio.Livres[i].pages, " pages, paru le ", biblio.Livres[i].date.jour, "/", biblio.Livres[i].date.mois, "/", biblio.Livres[i].date.annee, "/ et écrit par ", biblio.Livres[i].nbrAuteursLivres, " auteur(s)"
		A la ligne
	finFaire
Fin 
```
```
Procédure Recherche(;biblio : Bibliotheque, contraintes[] : Contrainte, nbrContraintes : entier)
Début
	Avec selection; numContrainte, indiceLivres[MAX], nbLivres : entier
	
	répéter
		selection = MenuGeneral("Créer des contraintes\nCréer des groupes de contraintes\nModifier une contrainte/groupe de contraintes\nSupprimer une contrainte/groupe de contraintes\nEffectuer la recherche\nRetour",6)
		Selon (selection) faire
			Cas 1:
				Si (nbrContraintes < MAX) alors
					CreationContraintes(;biblio : Bibliotheque, contraintes[] : Contrainte, nbrContraintes : entier)
				Sinon
					Afficher "La limite du nombre de contraintes a été atteinte"
				finSi
			Cas 2:
				Si (nbrContraintes < MAX et nbrContraintes >= 2) alors
					CreationGroupesContraintes(;biblio : Bibliotheque, contraintes[] : Contrainte, nbrContraintes : entier)
				Sinon
					Afficher "La limite du nombre de contraintes a été atteinte ou alors vous n'avez pas créé 2 contraintes"
				finSi
			Cas 3:
				Si (nbrContraintes >= 1) alors
					ModificationContraintes(;biblio : Bibliotheque, contraintes[] : Contrainte, nbrContraintes : entier)
				Sinon
					Afficher "Vous devez avoir au minimum 1 contrainte pour la modifier"
				finSi
			Cas 4:
				Si (nbrContraintes >= 1) alors
					SuppressionContraintes(;biblio : Bibliotheque, contraintes[] : Contrainte, nbrContraintes : entier)
				Sinon
					Afficher "Vous devez avoir au minimum 1 contrainte pour la supprimer"
				finSi
			Cas 5:
				Si (nbrContraintes >= 1) alors
					numContrainte = MenuGeneral(creationListeContraintes(contraintes, nbrContraintes), nbrContraintes)
					Si (numContrainte < nbrContrainte) alors
						RechercheLivres(;biblio, contraintes, contraintes[numContraintes], indiceLivres, nbLivres)
					finSi
				Sinon
					Afficher "Vous devez avoir au minimum 1 contrainte pour effectuer une recherche"
				finSi
			Cas 6:
				
			Defaut:
				Afficher "Erreur inconnue dans le choix du menu sur la RECHERCHE!"
		finFaire
	Tant que (selection != 6)
Fin 
```
```
Fonctions () retourne
Début

Fin 
```
```
Procédure RechercheLivres(;biblio : bibliotheque, contraintes[] : Contrainte, coontrainteActuelle : Contrainte, indiceLivres[] : entier, nbLivres : entier)
Début
	Avec indiceLivres2[MAX], nbLivres2 : entier
	type, data : chaîne
	
	Si (contrainteActuelle.positionContrainte1 = contrainteActuelle.positionContrainte2) alors
		decompositionContrainte(contrainteActuelle.contrainte1 ; type, data)
		
		Si (type = "TitreCompletLivre") alors
			rechercheLivresTitreComplet(biblio, data, indiceLivres, nbLivres)
		finSi
		Si (type = "TitreBoutLivre") alors
			rechercheLivresTitreBout(biblio, data, indiceLivres, nbLivres)
		finSi
		Si (type = "GenreLivre") alors
			rechercheLivresGenre(biblio, data, indiceLivres, nbLivres)
		finSi
		Si (type = "DateLivre") alors
			rechercheLivresDate(biblio, convertString2Date(data), indiceLivres, nbLivres)
		finSi
		Si (type = "NomAuteur") alors
			rechercheLivresAuteurNom(biblio, data, indiceLivres, nbLivres)
		finSi
		Si (type = "PrenomAuteur") alors
			rechercheLivresAuteurPrenom(biblio, data, indiceLivres, nbLivres)
		finSi
		Si (type = "NaissanceAuteur") alors
			rechercheLivresAuteurNaissance(biblio, convertString2Date(data), indiceLivres, nbLivres)
		finSi
		Si (type = "MortAuteur") alors
			rechercheLivresAuteurMort(biblio, convertString2Date(data), indiceLivres, nbLivres)
		finSi
	Sinon
		RechercheLivres(biblio, contraintes, contraintes[contrainteActuelle.positionContrainte1], indiceLivres, nbLivres)
		RechercheLivres(biblio, contraintes, contraintes[contrainteActuelle.positionContrainte2], indiceLivres2, nbLivres2)

		Si (contrainteActuelle.operateur = "et") alors
			intersectListes(indiceLivres, nbLivres, indiceLivres2, nbLivres2)
		Sinon
			unionListes(indiceLivres, nbLivres, indiceLivres2, nbLivres2)
		finSi
	finSi
Fin 
```

	> Before starting to sync files, you must link an account in the **Synchronize** sub-menu.
- HTML: publish the file converted to HTML via a Handlebars template (on a blog for example).
> **Note:** The **Publish now** button is disabled if your file has not been published yet.

