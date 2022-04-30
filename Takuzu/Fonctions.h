//
// Created by chesn on 30/04/2022.
//

#ifndef TAKUZU_FONCTIONS_H
#define TAKUZU_FONCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/// Menus
void menu_principal(char* choix);
void menu_jouer(char* choix);

/// Grilles
void choix_taille(int* taille, char *choix);
int* creer_grille(int taille);
int* generer_grille_solution(int taille, char* choix);
void trouver_grille(int *grille_solution, int taille, char* choix);
void numero_grille_hasard(int taille, char* numero_ligne, char* choix);


/// Jouer

void jouer(int grille_solution, int grille_masque, int grille_jeu);

/// Verifications



#endif //TAKUZU_FONCTIONS_H
