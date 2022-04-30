//
// Created by chesn on 01/04/2022.
//

#ifndef TP9_LISTE_H
#define TP9_LISTE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// S T R U C T U R E S //
typedef struct MAILLON MAILLON;

struct MAILLON {
    int valeur;
    MAILLON * succ;
} ;
//
typedef MAILLON* LISTE;

// P R O T O T Y P E S //
MAILLON* creer_maillon(int);
bool liste_vide(LISTE);
LISTE ajouter_tete_liste(LISTE, int);
LISTE ajouter_queue_liste(LISTE, int);
int taille_liste(LISTE);
void afficher_liste(LISTE);
LISTE creer_liste(int);
int somme_liste(LISTE);
int max_liste(LISTE);
int nombre_occurence_liste(LISTE, int);
LISTE concatener_deux_listes(LISTE, LISTE);
int* copier_liste_tab(LISTE);
LISTE ajouter_milieu_liste(LISTE, MAILLON*, int);
LISTE creer_liste_triee_croissant(int);
LISTE inverser_liste(LISTE) ;


#endif //TP9_LISTE_H
