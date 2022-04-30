//
// Created by chesn on 30/04/2022.
//

#include "menus.h"

int menu_pricipal(){
    int choix;
    do {
        printf("***** MENU PRICIPAL *****\n\n\n");
        printf(" 1. Jouer\n");
        printf(" 2. Résoudre une grille\n");
        printf(" 3. Générer une grille\n");
        printf("\nChoix : ");
        scanf(" %d", &choix);
    }while (choix < 1 || choix > 3);
    return choix;
}