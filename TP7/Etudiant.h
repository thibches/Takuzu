//
// Created by chesn on 18/03/2022.
//

#ifndef TP7_ETUDIANT_H
#define TP7_ETUDIANT_H
#include "Date.h"


typedef struct {
    char nom[30];
    char prenom[30];
    DATE dateNaissance;
    long numEtud;
    double moyenne;
}ETUDIANT;
void lireEtudiant(ETUDIANT*);
void afficherEtudiant(ETUDIANT*);


#endif //TP7_ETUDIANT_H
