//
// Created by chesn on 30/04/2022.
//

#include "Fonctions.h"

/// Menus
void menu_principal(int* choix){
    // boucle pour choix sécurisé
    do {
        fflush(stdin);
        // affichage menu
        printf("\n***** MENU PRICIPAL *****\n"
               "  1. Jouer\n"
               "  2. R\x82soudre une grille\n"
               "  3. G\x82n\x82rer une grille\n"
               "  4. Quitter\n"
               "Choix :");

        // enregistrement choix
        scanf(" %d", choix);
        // affichage message erreur si choix invalide
        if (*choix < 1 || *choix > 4){
            printf("\nErreur : choix non valide !\n");
        }

    }while (*choix < 1 || *choix > 4);

    // selon choix menu pricipal
    switch (*choix){

        // choix : jouer
        case 1:{
            // afficher menu jouer
            menu_jouer(choix);
            break;
        }

            // choix : résoudre une grille
        case 2:{
            printf("2");
            break;
        }

            // choix : générer une grille
        case 3:{
            printf("3");
            break;
        }

            // choix : quitter
        case 4:{
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

void menu_jouer(int* choix){
    // boucle pour choix sécurisé
    do {
        fflush(stdin);
        // affichage menu
        printf("\n***** MENU JOUER *****\n"
               "  1. Saisie manuelle du masque\n"
               "  2. Saisie automatique du masque\n"
               "  3. Jouer\n"
               "  4. Retour\n"
               "Choix :");

        // enregistrement choix
        scanf(" %d", choix);

        // affichage message erreur si choix invalide
        if (*choix < 1 || *choix > 4){
            printf("\nErreur : choix non valide !\n");
        }

    }while (*choix < 1 || *choix > 4);

    // selon choix : menu jouer
    switch (*choix){

        // choix : saisie manuelle du masque
        case 1:{
            // choix taille
            int taille;
            choix_taille(&taille, choix);
            printf("1");
            break;
        }

        // choix : saisie automatique du masque
        case 2:{
            // choix taille
            int taille;
            choix_taille(&taille, choix);
            printf("2");
            break;
        }

        // choix : jouer
        case 3:{
            // choix de la taille
            int taille;
            choix_taille(&taille, choix);
            // création grille solution
            int *grille_solution = generer_grille_solution(taille, choix);
            // création grille masque
            int* grille_masque = generer_grille_masque(taille);
            // création de la grille jeu
            int* grille_jeu = generer_grille_jeu(taille, grille_solution, grille_masque);
            // jouer
            jouer(taille, grille_jeu, choix);
            break;
        }

        // choix : retour
        case 4:{
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
void choix_taille(int* taille, int *choix){
    // boucle pour choix sécurisé
    do {
        printf("\n***** Taille *****\n"
               "  1. 4x4\n"
               "  2. 8x8\n"
               "  3. Retour\n"
               "Choix :");
        scanf(" %d", choix);
        if (*choix < 1 || *choix > 3){
            printf("Erreur : choix non valide !");
        }
    }while (*choix < 1 || *choix > 3);
    // selon taille choisie
    switch (*choix){
        // choix : 4x4
        case 1:{
            *taille = 16;
            break;
        }
        //choix : 8x8
        case 2:{
            *taille = 64;
            break;
        }
        //choix : retour
        case 3: {
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

int* generer_grille_solution(int taille, int* choix){
    int* grille_solution;
    // création de la grille vide
    grille_solution = creer_grille(taille);
    // remplissage de la grille solution
    trouver_grille(grille_solution, taille, choix);
    return grille_solution;
}

void numero_grille_hasard(int taille, char* numero_ligne, int* choix){
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
            }
            if (nbr_lignes != 0){
                nbr_lignes ++;
            }
            // choix au hasard d'une ligne du fichier
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
            }
            if (nbr_lignes != 0){
                nbr_lignes ++;
            }
            // choix au hasard d'une ligne du fichier
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

void trouver_grille(int *grille_solution, int taille, int* choix){
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
            // lecture du fichier jusqu'a ce que la ligne choisie soit trouvée
            bool verif_grille = false;
            char solution[taille];
            while (fgets(solution, taille+2, sp) != NULL && verif_grille == false){
                // vérification de la ligne
                if (solution[0] == numero_ligne[0]){
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
            while (fgets(solution, taille + 2, sp) != NULL && verif_grille == false){
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

int* generer_grille_masque(int taille){
    int* grille_masque;
    // création de la grille vide
    grille_masque = creer_grille(taille);
    // remplissage de la grille masque
    int case_visible = (taille / 2) - (taille / 8);
    srand(time(NULL));
    for(int i=0; i < case_visible; i++) {
        int numero_case = rand() % taille;
        if (grille_masque[numero_case] == 0) {
            grille_masque[numero_case] = 1;
        }
        else{
            i --;
        }
    }
    return grille_masque;
}

int* generer_grille_jeu(int taille, int *grille_solution, int *grille_masque){
    int* grille_jeu;
    // création de la grille jeu
    grille_jeu = creer_grille(taille);
    // remplissage de la grille
    for(int i =0; i < taille; i++){
        if (grille_masque[i] == 0){
            grille_jeu[i] = 3;
        }
        else{
            grille_jeu[i] = grille_solution[i];
        }
    }
    return grille_jeu;
}

/// Jouer

void jouer(int taille, int *grille_jeu,int *choix){
    char colonne;
    int ligne;
    bool verif;
    char c = '\x82';
    // boucle de saisie sécurisée
    do {
        //affichage interface
        printf("\n***** Jouer *****\n\n");
        afficher_grille(taille, grille_jeu);
        printf("\n\nSaisir les coordonn%ces d'une case  ou taper '00' pour retourner au menu principal\n"
               "Saisie : ", c);
        scanf(" %c %d", &colonne, &ligne);
        verif = verif_saisie(taille, colonne, ligne);
        // message erreur si saisie incorect
        if (verif != true) {
            printf("\nErreur : saisie incorrect !\n");
        }
    } while (verif != true);
    if (colonne == '0')
        menu_jouer(choix);
    else {
        int indice = convertir_coordonnees(taille, colonne, ligne);
        if (grille_jeu[indice] != 3){
            printf("\nErreur : la case s%clectionn%ce ne peut pas \x88tre modifi%ce\n", c, c, c);
            jouer(taille, grille_jeu, choix);
        }
        else {
            int reponse;
            do{
                fflush(stdin);
                printf("\nSaisir 0 ou 1 : ");
                scanf(" %d", &reponse);
                if (reponse != 0 && reponse != 1)
                    printf("\nErreur : saisie incorrecte\n");
                }while(reponse != 0 && reponse != 1);
            verif_reponse(grille_jeu, indice, taille, reponse);
        }
    }
}

void afficher_grille(int taille,int *grille){
    // nombre de lignes nécessaires à l'affichage
    int nbr_lignes = sqrt(taille) * 2;
    // affichage haut de la grille
    if (nbr_lignes == 8)
        printf("     A    B    C    D\n"
            "  \xda\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xbf");
    else
        printf("     A    B    C    D    E    F    G    H\n"
               "  \xda\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xbf");
    int cpt =1;
    for (int i = 0; i < nbr_lignes; i++) {
        if ((i == 0 || i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14) && i < nbr_lignes) {
            printf("\n%d \xb3", cpt);
            cpt++;
            for (int j = 2 * i; j <  2 * i + nbr_lignes / 2; j++){
                if (grille[j] == 3)
                    printf("    \xb3");
                else
                    printf("  %d \xb3", grille[j]);
            }
        }
        else if (nbr_lignes == 8){
            if (i == 7)
                printf("\n  \xc0\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xd9");
            else
                printf("\n  \xc3\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xb4");
        }
        else{
            if (i == 15)
                printf("\n  \xc0\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xd9");
            else
                printf("\n  \xc3\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xb4");
        }
    }
}

bool verif_saisie(int taille, char colonne, int ligne){
    if (colonne == '0')
        return true;
    if(colonne != 'a' && colonne != 'b' && colonne != 'c' && colonne != 'd' && colonne != 'e' && colonne != 'f' && colonne != 'g' && colonne != 'h')
        if(colonne != 'A' && colonne != 'B' && colonne != 'C' && colonne != 'D' && colonne != 'E' && colonne != 'F' && colonne != 'G' && colonne != 'H')
            return false;
    if (taille == 16 && colonne != 'a' && colonne != 'b' && colonne != 'c' && colonne != 'd' && colonne != 'A' && colonne != 'B' && colonne != 'C' && colonne != 'D')
        return false;
    if (ligne != 1 && ligne != 2 && ligne != 3 && ligne != 4 && ligne != 5 && ligne != 6 && ligne != 7 && ligne != 8)
        return false;
    if (taille == 16 && ligne != 1 && ligne != 2 && ligne != 3 && ligne != 4)
        return false;
    return true;
}

int convertir_coordonnees(int taille, char colonne, int ligne){
    taille = sqrt(taille);
    int cln = colonne;
    if (cln >= 97)
        cln -= 97;
    else
        cln -= 65;
    ligne -= 1;
    return cln + ligne * taille;
}

/// Vérification

void verif_reponse(int *grille_jeu, int indice, int taille, int reponse){
    int grille_test[taille];
    for (int i = 0; i < taille; i ++)
        grille_test[i] = grille_jeu[i];
    grille_test[indice] = reponse;
    bool verif = true;
    while (verif) {
        verif_ligne(grille_test, taille, &verif);
        verif_colonne(grille_test, taille, &verif);
        break;
    }
    if (verif)
        printf("ok");
    else
        printf("no");

}

void verif_ligne(int *grille_test, int taille, bool *verif){
    taille = sqrt(taille);
    int cpt0 = 0;
    int cpt1 = 0;
    while (*verif) {
        for (int i = 0; i < taille; i++) {
            for (int j = 0; j < taille; j++) {
                if (grille_test[i * taille + j] == 0)
                    cpt0++;
                else if (grille_test[i * taille + j] == 1)
                    cpt1++;
            }
            if (cpt0 > taille / 2 || cpt1 > taille / 2) {
                *verif = false;
                break;
            }
            cpt0 = 0;
            cpt1 = 0;
        }
        break;
    }
}

void verif_colonne(int *grille_test, int taille, bool *verif){
    taille = sqrt(taille);
    int cpt0 = 0;
    int cpt1 = 0;
    while (*verif) {
        for (int i = 0; i < taille; i++) {
            for (int j = i; j < taille * taille; j +=4){
                if (grille_test[j] == 0)
                    cpt0++;
                else if (grille_test[j] == 1)
                    cpt1++;
            }
            if (cpt0 > taille / 2 || cpt1 > taille / 2) {
                *verif = false;
                break;
            }
            cpt0 = 0;
            cpt1 = 0;
        }
        break;
    }
}



