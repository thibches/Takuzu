//
// Created by chesn on 18/03/2022.
//

#include "Etudiant.h"

void lireEtudiant(ETUDIANT* etudiant){
    printf("Saisir informations de l'étudiant :\n");
    printf("Nom : \n");
    scanf(" %s", etudiant->nom);
    printf("Prénom : \n");
    scanf(" %s", etudiant->prenom);
    printf("Date de naissance : \n");
    lireDate(&etudiant->dateNaissance);
    printf("Numéro étudiant : \n");
    scanf(" %ld", &etudiant->numEtud);
    printf("Moyenne : \n");
    scanf(" %lf", &etudiant->moyenne);
}
void afficherEtudiant(ETUDIANT* etudiant){
    printf("OK");
    printf("nom : %s\n", etudiant->nom);
    printf("prénom : %s\n", etudiant->prenom);
    //printf("date de naissance : %d/%d/%d\n", etudiant->dateNaissance.jour, etudiant->dateNaissance.mois, etudiant->dateNaissance.annee);
    afficherDate(&etudiant->dateNaissance);
    printf("Numéro étudiant : %ld\n", etudiant->numEtud);
    printf("Moyenne : %.2lf\n", etudiant->moyenne);
}

