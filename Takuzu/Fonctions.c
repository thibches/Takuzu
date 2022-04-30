//
// Created by chesn on 30/04/2022.
//

#include "Fonctions.h"

/// Menus
void menu_principal(char* choix){
    // boucle pour choix sécurisé
    do {

        // affichage menu
        printf("\n***** MENU PRICIPAL *****\n"
               "  1. Jouer\n"
               "  2. R\x82soudre une grille\n"
               "  3. G\x82n\x82rer une grille\n"
               "  4. Quitter\n"
               "Choix :");

        // enregistrement choix
        scanf(" %c", choix);

        // affichage message erreur si choix invalide
        if (*choix != '1' && *choix != '2' && *choix != '3' && *choix != '4'){
            printf("\nErreur : choix non valide !\n");
        }

    }while (*choix != '1' && *choix != '2' && *choix != '3' && *choix != '4');

    // selon choix menu pricipal
    switch (*choix){

        // choix : jouer
        case '1':{
            // afficher menu jouer
            menu_jouer(choix);
            break;
        }

            // choix : résoudre une grille
        case '2':{
            printf("2");
            break;
        }

            // choix : générer une grille
        case '3':{
            printf("3");
            break;
        }

            // choix : quitter
        case '4':{
            printf("\nA bient\x93t !\n");
            break;
        }

            // Retour menu principal si erreur inconnue
        default:{
            printf("\nErreur menu principal.\n"
                   "Contactez les cr\x82taurs : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
            menu_principal(choix);
        }

    }
}

void menu_jouer(char* choix){
    // boucle pour choix sécurisé
    do {

        // affichage menu
        printf("\n***** MENU JOUER *****\n"
               "  1. Saisie manuelle du masque\n"
               "  2. Saisie automatique du masque\n"
               "  3. Jouer\n"
               "  4. Retour\n"
               "Choix :");

        // enregistrement choix
        scanf(" %c", choix);

        // affichage message erreur si choix invalide
        if (*choix != '1' && *choix != '2' && *choix != '3' && *choix != '4'){
            printf("\nErreur : choix non valide !\n");
        }

    }while (*choix != '1' && *choix != '2' && *choix != '3' && *choix != '4');

    // selon choix : menu jouer
    switch (*choix){

        // choix : saisie manuelle du masque
        case '1':{
            // choix taille
            int taille;
            choix_taille(&taille, choix);
            printf("1");
            break;
        }

        // choix : saisie automatique du masque
        case '2':{
            // choix taille
            int taille;
            choix_taille(&taille, choix);
            printf("2");
            break;
        }

        // choix : jouer
        case '3':{
            // choix de la taille
            int taille;
            choix_taille(&taille, choix);
            // création grille solution
            int *grille_solution = generer_grille_solution(taille, choix);

            for (int i =0; i < taille; i++){
                printf("%d", grille_solution[i]);
            }

            break;
        }

        // choix : retour
        case '4':{
            menu_principal(choix);
            break;
        }

        // Retour menu jouer si erreur inconnue
        default:{
            printf("\nErreur menu jouer.\n"
                   "Contactez les cr\x82taurs : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
            menu_jouer(choix);
        }

    }
}

/// Grilles
void choix_taille(int* taille, char *choix){
    // boucle pour choix sécurisé
    do {
        printf("\n***** Taille *****\n"
               "  1. 4x4\n"
               "  2. 8x8\n"
               "  3. Retour\n"
               "Choix :");
        scanf(" %c", choix);
        if (*choix != '1' && *choix != '2' && *choix != '3'){
            printf("Erreur : choix non valide !");
        }
    }while (*choix != '1' && *choix != '2' && *choix != '3');
    // selon taille choisie
    switch (*choix){
        // choix : 4x4
        case '1':{
            *taille = 16;
            break;
        }
        //choix : 8x8
        case '2':{
            *taille = 64;
            break;
        }
        //choix : retour
        case '3': {
            menu_jouer(choix);
            break;
        }
        // Retour menu jouer si erreur inconnue
        default:{
            printf("\nErreur choix taille.\n"
                   "Contactez les cr\x82taurs : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
            menu_jouer(choix);
        }
    }
}

int* creer_grille(int taille){
    int *grille;
    // création d'un tableau dynamique de taille souhaitée
    grille = (int *) calloc(taille, sizeof(int));
    return grille;
}

int* generer_grille_solution(int taille, char* choix){
    int* grille_solution;
    // créationde la grille vide
    grille_solution = creer_grille(taille);
    // remplissage de la grille solution
    trouver_grille(grille_solution, taille, choix);
    return grille_solution;
}

void numero_grille_hasard(int taille, char* numero_ligne, char* choix){
    // selon taille choisie
    switch (taille) {
        // taille choisie = 4x4
        case 16: {
            // ouverture du fichier "grilles 4x4.txt"
            FILE *sp = fopen("grilles 4x4.txt", "r");
            // verification de bonne ouverture du fichier
            if (sp == NULL) {
                printf("\nErreur inconnue !\n"
                       "Contactez les Admins : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                menu_jouer(choix);
            }
            // compte le nombre de lignes du fichier
            int c;
            int nbr_lignes = 0;
            while ((c = fgetc(sp)) != EOF) {
                if (c == '\n') {
                    nbr_lignes++;
                }
                nbr_lignes ++;
            }
            // choix au hasard d'une ligne du fichier
            srand(time(NULL));
            int numero_grille = rand() % nbr_lignes;
            // convertion de l'entier numero_grille en caractère numero_ligne
            itoa(numero_grille, numero_ligne, 10);
            break;
        }
        // taille choisie = 8x8
        case 64: {
            // ouverture du fichier "grilles 8x8.txt"
            FILE *sp = fopen("grilles 8x8.txt", "r");
            // verification de bonne ouverture du fichier
            if (sp == NULL) {
                printf("\nErreur inconnue !\n"
                       "Contactez les Admins : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                menu_jouer(choix);
            }
            // compte le nombre de lignes du fichier
            int c;
            int nbr_lignes = 0;
            while ((c = fgetc(sp)) != EOF) {
                if (c == '\n') {
                    nbr_lignes++;
                }
                nbr_lignes ++;
            }
            // choix au hasard d'une ligne du fichier
            srand(time(NULL));
            int numero_grille = rand() % nbr_lignes;
            // convertion de l'entier numero_grille en caractère numero_ligne
            itoa(numero_grille, numero_ligne, 10);
            break;
        }
        // Retour menu jouer si erreur inconnue
        default: {
            printf("\nErreur numero grille hasard.\n"
                   "Contactez les cr\x82taurs : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
            menu_jouer(choix);
        }
    }
}

void trouver_grille(int *grille_solution, int taille, char* choix){
    // selon taille choisie
    switch (taille){
        // taille choisie = 4x4
        case 16:{
            // ouverture du fichier "grilles 4x4.txt"
            FILE *sp = fopen("grilles 4x4.txt", "r");
            // verification de la bonne ouverture du fichier
            if (sp == NULL){
                printf("\nErreur inconnue !\n"
                       "Contactez les Admins : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                menu_jouer(choix);            }
            // choix au hasard d'un numéro de ligne du fichier
            char numero_ligne[0];
            numero_grille_hasard(taille, numero_ligne,choix);
            char nbr_ligne = numero_ligne[0];
            char solution[taille];
            bool verif_grille = false;
            // lecture du fichier jusqu'a ce que la ligne choisie soit trouvée
            while (fgets(solution, taille, sp) != NULL && verif_grille == false){
                // vérification de la ligne
                if (solution[0] == nbr_ligne){
                    // remplissage de la matrice solution avec la ligne correspondante
                    for(int i = 0; i < taille; i++){
                        if (solution[i+1] == '0'){
                            grille_solution[i] = 0;
                        }
                        else{
                            grille_solution[i] = 1;
                        }
                    }
                    // condition d'arret de lecture du fichier
                    verif_grille = true;
                }
            }
            break;
        }
        // taille choisie = 8x8
        case 64:{
            // ouverture du fichier "grilles 8x8.txt"
            FILE *sp = fopen("grilles 8x8.txt", "r");
            // verification de la bonne ouverture du fichier
            if (sp == NULL){
                printf("\nErreur inconnue !\n"
                       "Contactez les Admins : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                menu_jouer(choix);            }
            // choix au hasard d'un numéro de ligne du fichier
            char numero_ligne[0];
            numero_grille_hasard(taille, numero_ligne,choix);
            char nbr_ligne = numero_ligne[0];
            char solution[taille];
            bool verif_grille = false;
            // lecture du fichier jusqu'a ce que la ligne choisie soit trouvée
            while (fgets(solution, taille, sp) != NULL && verif_grille == false){
                // vérification de la ligne
                if (solution[0] == nbr_ligne){
                    // remplissage de la matrice solution avec la ligne correspondante
                    for(int i = 0; i < taille; i++){
                        if (solution[i+1] == '0'){
                            grille_solution[i] = 0;
                        }
                        else{
                            grille_solution[i] = 1;
                        }
                    }
                    // condition d'arret de lecture du fichier
                    verif_grille = true;
                }
            }
            break;
        }
        // Retour menu jouer si erreur inconnue
        default:{
            printf("\nErreur trouver grille.\n"
                   "Contactez les cr\x82taurs : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
            menu_jouer(choix);
        }
    }
}


/// Jouer

void jouer(int grille_solution, int grille_masque, int grille_jeu){}

/// Vérification





