//
// Created by chesn on 30/04/2022.
//

#ifndef TAKUZU_FONCTIONS_H
#define TAKUZU_FONCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <unistd.h>


/// Menus
void menu_principal(int* choix);
void menu_jouer(int* choix);

/// Grilles
void choix_taille(int* taille, int *choix);
int* creer_grille(int taille);
int* generer_grille_solution(int taille, int* choix);
void trouver_grille(int *grille_solution, int taille, int* choix);
void numero_grille_hasard(int taille, char* numero_ligne, int* choix);
int* generer_grille_masque(int taille);
int* generer_grille_jeu(int taille, int *grille_solution, int *grille_masque);



/// Jouer
void jouer(int taille, int *grillle_solution, int *grille_jeu, int *choix);
void afficher_grille(int taille, int *grille);
bool verif_saisie(int taille, char colonne, int ligne);
int convertir_coordonnees(int taille, char colonne, int ligne);
bool grille_complete(int taille, int *grille_jeu);

/// Verifications
bool verif_reponse(int *grille_jeu, int indice, int taille, int reponse, int *choix);
void verif_ligne(int *grille_test, int taille, bool *verif);
void verif_colonne(int *grille_test, int taille, bool *verif);


#endif //TAKUZU_FONCTIONS_H
