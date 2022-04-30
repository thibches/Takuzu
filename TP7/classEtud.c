//
// Created by chesn on 20/03/2022.
//

#include "classEtud.h"

void lireTabEtudiants(ETUDIANT ** T, int N ){
    *T = (ETUDIANT*) calloc(N, sizeof (ETUDIANT));
    for (int i = 0; i < N; i++){
        lireEtudiant(&(*T)[i]);
    }
}
void afficherTabEtudiants(ETUDIANT * T, int N){
    for (int i=0; i < N; i++){
        afficherEtudiant(&T[i]);
    }
}

