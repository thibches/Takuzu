//
// Created by chesn on 20/03/2022.
//

#ifndef TP7_CLASSETUD_H
#define TP7_CLASSETUD_H
#include "Etudiant.h"

typedef struct {
    ETUDIANT * listEtud;
    long nbEtud;
    double moyClasse;
}CLASS_ETUD;

void lireTabEtudiants(ETUDIANT ** T, int N );
void afficherTabEtudiants(ETUDIANT * T, int N);
double moyTabEtudiants(ETUDIANT * T, int N);
int meilleurMoy(ETUDIANT * T, int N);
int plusJeuneEtudiant(ETUDIANT * T, int N);
void lireClasse(CLASS_ETUD *);
void afficherClasse(CLASS_ETUD *);
void libClasseEtud(CLASS_ETUD *);

#endif //TP7_CLASSETUD_H
