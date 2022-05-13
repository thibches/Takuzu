//
// Created by chesn on 30/04/2022.
//

#include "Fonctions.h"

/// Menus
void menu_principal(int* choix){
    // boucle pour choix sécurisé
    do {
        *choix = 0;
        fflush(stdin);
        // affichage menu
        printf("\n***** MENU PRICIPAL *****\n"
               "  1. Jouer\n"
               "  2. R\x82soudre une grille\n"
               "  3. G\x82n\x82rer une grille\n"
               "Choix :");

        // enregistrement choix
        scanf(" %d", choix);
        // affichage message erreur si choix invalide
        if (*choix < 1 || *choix > 3){
            printf("\nErreur : choix non valide !\n");
        }

    }while (*choix < 1 || *choix > 3);

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
            // choix taille
            int taille;
            choix_taille(&taille, choix);
            // création grille solution
            int *grille_solution = generer_grille_solution(taille, choix);
            // création grille masque
            int* grille_masque = generer_grille_masque(taille);
            // création de la grille jeu
            int* grille_jeu = generer_grille_jeu(taille, grille_solution, grille_masque);
            resoudre(taille, grille_solution, grille_jeu, choix);
            menu_principal(choix);
            break;
        }

            // choix : générer une grille
        case 3:{
            printf("\nFonctionalit\x82 bient\x93t disponible !\n");
            menu_principal(choix);
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
        *choix = 0;
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
        case 1: {
            // choix taille
            int taille;
            choix_taille(&taille, choix);
            // création grille solution
            int *grille_solution = generer_grille_solution(taille, choix);
            // création grille masque
            int *grille_masque = creer_grille(taille);
            char colonne;
            int ligne;
            bool verif;
            bool masque = true;
            char c = '\x82';
            do {
                // boucle de saisie sécurisée
                do {
                    //affichage interface
                    printf("\n***** Masque manuel *****\n\n");
                    afficher_grille(taille, grille_masque, -1);
                    printf("\n\nSaisir les coordonn%ces d'une case ou taper '00' pour retourner au menu jouer.\n"
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
                    int reponse;
                    do {
                        fflush(stdin);
                        printf("\nSaisir 0 (case invisible) ou 1 (case visible : ");
                        scanf(" %d", &reponse);
                        if (reponse != 0 && reponse != 1)
                            printf("\nErreur : saisie incorrecte\n");
                    } while (reponse != 0 && reponse != 1);
                    grille_masque[indice] = reponse;
                    do{
                        *choix = 0;
                        fflush(stdin);
                        printf("\n1. Continuer\n"
                               "2. Jouer\n"
                               "3. Retour\n"
                               "Choix : ");
                        scanf(" %d", choix);
                        if (*choix < 0 || *choix > 3)
                            printf("\nErreur : saisie non valide");
                    }while(*choix < 0 || *choix > 3);
                    switch (*choix) {
                        case 1:
                            break;
                        case 2:{
                            int *grille_jeu = generer_grille_jeu(taille, grille_solution, grille_masque);
                            masque = false;
                            jouer(taille, grille_solution, grille_jeu, choix);
                            break;
                        }
                        case 3: {
                            masque = false;
                            break;
                        }
                        default:{
                            masque = false;
                            printf("\nErreur masque manuel.\n"
                                   "Contactez les cr\x82taurs : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                        }
                    }
                }
            }while(masque == true);
            menu_jouer(choix);
            break;
        }

        // choix : saisie automatique du masque
        case 2:{
            // choix taille
            int taille;
            choix_taille(&taille, choix);
            // création grille solution
            int *grille_solution = generer_grille_solution(taille, choix);
            // création grille masque
            int* grille_masque = generer_grille_masque(taille);
            // création de la grille jeu
            int* grille_jeu = generer_grille_jeu(taille, grille_solution, grille_masque);
            printf("\n***** Masque automatique *****\n");
            afficher_grille(taille, grille_masque, -1);
            printf("\n\n");
            afficher_grille(taille, grille_jeu,-1);
            do{
                *choix = 0;
                fflush(stdin);
                printf("\n\n1. Jouer\n"
                       "2. Retour\n"
                       "Saisie : ");
                scanf(" %d", choix);
                if (*choix != 1 && *choix != 2)
                    printf("Erreur : saisie non valide");
            }while (*choix != 1 && *choix != 2);
            if (*choix == 1)
                jouer(taille, grille_solution, grille_jeu, choix);
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
            jouer(taille, grille_solution, grille_jeu, choix);
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
        }
    }
    menu_jouer(choix);
}

/// Grilles
void choix_taille(int* taille, int *choix){
    // boucle pour choix sécurisé
    do {
        *choix = 0;
        fflush(stdin);
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

void jouer(int taille, int *grille_solution, int *grille_jeu,int *choix){
    char colonne;
    int ligne;
    bool verif; //savoir si une réponse est correct
    int vie = 3; //nombre de vies
    int aide = 3; // nombre d'aide
    char c = '\x82'; // é
    bool resultat = true;
    bool fait = false; // savoir si l'aide a été utilisée
    // boucle tant que grille pas finie
    do {
        do{
            *choix = 0;
            fflush(stdin);
            //affichage interface
            printf("\n***** Jouer *****\n\n");
            afficher_grille(taille, grille_jeu,-1);
            fflush(stdin);
            printf("\n\nVous avez : %d vies\n"
                   "1. Saisir coordon%ces d'une case\n"
                   "2. Indice %d/3\n"
                   "3. Quitter\n"
                   "Choix : ", vie, c, aide);
            scanf("%d", choix);
            if(*choix<1 || *choix>3){
                printf("\nErreur : choix non valide !\n");
            }
        } while (*choix<1 || *choix>3);
        switch (*choix) {
            // jouer
            case 1:{
                do {
                    fflush(stdin);
                    printf("\nCoordon%ces : ", c);
                    scanf(" %c %d", &colonne, &ligne);
                    verif = verif_saisie(taille, colonne, ligne);
                    // message erreur si saisie incorect
                    if (verif != true) {
                        printf("\nErreur : saisie incorrect !\n");
                    }
                } while (verif != true);
                int indice = convertir_coordonnees(taille, colonne, ligne);
                if (grille_jeu[indice] != 3) {
                    printf("\nErreur : la case s%clectionn%ce ne peut pas \x88tre modifi%ce.\n", c, c, c);
                }
                else {
                    int reponse;
                    do {
                        fflush(stdin);
                        printf("\nSaisir 0 ou 1 : ");
                        scanf(" %d", &reponse);
                        if (reponse != 0 && reponse != 1)
                            printf("\nErreur : saisie incorrecte\n");
                    } while (reponse != 0 && reponse != 1);
                    verif = verif_reponse(grille_jeu, indice, taille, reponse, true);
                    if (verif == false) {
                        vie--;
                        if (vie == 0)
                            resultat = false;
                    }
                    else {
                        if (reponse != grille_solution[indice] && taille != 16)
                            printf("\nCoup valide mais incorrect !\n");
                        else
                            grille_jeu[indice] = reponse;
                    }
                }
                break;
            }
            // indice
            case 2:{
                if(aide>0) {
                    aide--;
                    do {
                        int indice = rand() % taille - 1;
                        if (grille_jeu[indice] == 3) {
                            if (verif_reponse(grille_jeu, indice, taille, 0, false) == true)
                                grille_jeu[indice] = 0;
                            else
                                grille_jeu[indice] = 1;
                            fait = true;
                        }
                    } while (fait == false);
                    fait = false;
                }
                else
                    printf("\nPlus d'indice disponible !\n");
                break;
            }
            // quitter
            case 3:{
                menu_jouer(choix);
                break;
            }
            // erreur inconnue
            default:{
                printf("\nErreur choix jouer.\n"
                       "Contactez les cr\x82taurs : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                menu_jouer(choix);
            }
        }
    }while(grille_complete(taille, grille_jeu) == false && resultat == true);
    printf("\n");
    afficher_grille(taille, grille_jeu,-1);
    if (resultat)
        printf("\n\nF\x82licitation !\n");
    else
        printf("\nPerdu ! Vous n'avez plus de vie.\n\n");
    system("pause");
    printf("\n");
}

void resoudre(int taille, int *grille_solution, int *grille_jeu, int *choix){
    char c = '\x82';
    taille = sqrt(taille);
    int lcpt0 = 0, lcpt1 = 0;
    int ccpt0 = 0, ccpt1 = 0;
    bool action = false;
    printf("\n");
    afficher_grille(taille*taille, grille_jeu,-1);
    printf("\n");
    system("pause");
    do {
        //printf("\n");
        //afficher_grille(taille*taille, grille_jeu);
        action = false;
        do {
            action = false;
            for (int i = 0; i < taille; i++) {
                ccpt0 = 0;
                ccpt1 = 0;
                lcpt0 = 0;
                lcpt1 = 0;
                for (int j = 0; j < taille; j++) {
                    // devant 0 et 1 d'affilés lignes
                    if (j > 0 && j < taille - 1)
                        if (grille_jeu[i * taille + j] == grille_jeu[i * taille + j + 1] &&
                            grille_jeu[i * taille + j - 1] == 3 && grille_jeu[i * taille + j] != 3) {
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[i * taille + j - 1] = 1;
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[i * taille + j - 1] = 0;
                            printf("\n\nCar il ne peut y avoir seulement deux %d d'affil\x82\n\n",
                                   grille_jeu[i * taille + j]);
                            action = true;
                            afficher_grille(taille * taille, grille_jeu,i * taille + j - 1);
                            system("pause");
                        }
                    // derriere 0 et 1 d'affilés lignes
                    if (j < taille - 2)
                        if (grille_jeu[i * taille + j] == grille_jeu[i * taille + j + 1] &&
                            grille_jeu[i * taille + j + 2] == 3 && grille_jeu[i * taille + j] != 3) {
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[i * taille + j + 2] = 1;
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[i * taille + j + 2] = 0;
                            printf("\n\nCar il ne peut y avoir seulement deux %d d'affil\x82\n\n",
                                   grille_jeu[i * taille + j]);
                            action = true;
                            afficher_grille(taille * taille, grille_jeu,i * taille + j + 2);
                            printf("\n");
                            system("pause");
                        }
                    // dessus 0 et 1 d'affilés colones
                    if (i > 0 && i < taille - 1)
                        if (grille_jeu[i * taille + j] == grille_jeu[(i + 1) * taille + j] &&
                            grille_jeu[(i - 1) * taille + j] == 3 && grille_jeu[(i) * taille + j] != 3) {
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[(i - 1) * taille + j] = 1;
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[(i - 1) * taille + j] = 0;
                            printf("\n\nCar il ne peut y avoir seulement deux %d d'affil\x82\n\n",
                                   grille_jeu[i * taille + j]);
                            action = true;
                            afficher_grille(taille * taille, grille_jeu,(i - 1) * taille + j);
                            printf("\n");
                            system("pause");
                        }
                    // dessous 0 et 1 d'affilés colones
                    if (i < taille - 2)
                        if (grille_jeu[i * taille + j] == grille_jeu[(i + 1) * taille + j] &&
                            grille_jeu[(i + 2) * taille + j] == 3 && grille_jeu[(i) * taille + j] != 3) {
                            grille_jeu[(i + 2) * taille + j] = grille_solution[(i + 2) * taille + j];
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[(i + 2) * taille + j] = 1;
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[(i + 2) * taille + j] = 0;
                            printf("\n\nCar il ne peut y avoir seulement deux %d d'affil\x82\n\n",
                                   grille_jeu[i * taille + j]);
                            action = true;
                            afficher_grille(taille * taille, grille_jeu,(i + 2) * taille + j);
                            printf("\n");
                            system("pause");
                        }
                    // entre deux valeurs identiques lignes
                    if (j < taille - 2)
                        if (grille_jeu[i * taille + j] == grille_jeu[i * taille + j + 2] &&
                            grille_jeu[i * taille + j + 1] == 3 && grille_jeu[i * taille + j] != 3) {
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[i * taille + j + 1] = 1;
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[i * taille + j + 1] = 0;
                            printf("\n\nCar il ne peut y avoir seulement un %d entre deux %d\n\n",
                                   grille_jeu[i * taille + j + 1], grille_jeu[i * taille + j]);
                            action = true;
                            afficher_grille(taille * taille, grille_jeu,i * taille + j + 1);
                            printf("\n");
                            system("pause");
                        }
                    // entre deux valeurs identiques colones
                    if (i < taille - 2)
                        if (grille_jeu[i * taille + j] == grille_jeu[(i + 2) * taille + j] &&
                            grille_jeu[(i + 1) * taille + j] == 3 && grille_jeu[i * taille + j] != 3) {
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[(i + 1) * taille + j] = 1;
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[(i + 1) * taille + j] = 0;
                            printf("\n\nCar il ne peut y avoir seulement un %d entre deux %d\n\n",
                                   grille_jeu[(i + 1) * taille + j], grille_jeu[i * taille + j]);
                            action = true;
                            afficher_grille(taille * taille, grille_jeu,(i + 1) * taille + j);
                            printf("\n");
                            system("pause");
                        }
                    // si grille a deja nombre max d une valeure lignes
                    if (grille_jeu[i * taille + j] == 0)
                        lcpt0++;
                    else if (grille_jeu[i * taille + j] == 1)
                        lcpt1++;
                    if (lcpt0 == taille / 2 || lcpt1 == taille / 2) {
                        for (int k = 0; k < taille; k++) {
                            if (grille_jeu[i * taille + k] == 3) {
                                if (lcpt0==taille/2)
                                    grille_jeu[i * taille + k] = 1;
                                else
                                    grille_jeu[i * taille + k] = 0;
                                printf("\n\nCar il y a %d valeurs oppos%ces dans la ligne\n\n", taille / 2, c);
                                action = true;
                                afficher_grille(taille * taille, grille_jeu,i * taille + k);
                                printf("\n");
                                system("pause");
                            }
                        }
                    }
                    // si grille a deja nombre max d une valeure colones
                    if (grille_jeu[j * taille + i] == 0)
                        ccpt0++;
                    else if (grille_jeu[j * taille + i] == 1)
                        ccpt1++;
                    if (ccpt0 == taille / 2 || ccpt1 == taille / 2) {
                        for (int k = 0; k < taille; k++) {
                            if (grille_jeu[k * taille + i] == 3) {
                                if (ccpt0==taille/2)
                                    grille_jeu[k * taille + i] = 1;
                                else
                                    grille_jeu[k * taille + i] = 0;
                                printf("\n\nCar il y a %d valeurs oppos%ces dans la colone\n\n", taille / 2, c);
                                action = true;
                                afficher_grille(taille * taille, grille_jeu,k * taille + i);
                                printf("\n");
                                system("pause");
                            }
                        }
                    }
                }

            }
        }while(action == true);
        // Ajout réponse par supposition lorsque les astuces ne fonctionnent pas
        bool supposition = false;
        for (int i = 0; i < taille; i++)
            for (int j = 0; j < taille; j++)
                if(grille_jeu[i*taille+j] == 3 && supposition == false){
                    if (verif_reponse(grille_jeu, i*taille+j, taille*taille, 0, false) == true) {
                        grille_jeu[i * taille + j] = 0;
                        printf("\n\nAjout d'un %d par supposition\n\n", grille_jeu[i * taille + j]);
                        afficher_grille(taille * taille, grille_jeu,i * taille + j);
                        printf("\n");
                        system("pause");
                    }
                    else {
                        grille_jeu[i * taille + j] = 1;
                        printf("\n\nAjout d'un %d par supposition\n\n", grille_jeu[i * taille + j]);
                        afficher_grille(taille * taille, grille_jeu,i * taille + j);
                        printf("\n");
                        system("pause");
                    }
                    supposition = true;
                }
    }while(grille_complete(taille*taille, grille_jeu) == false);
    printf("\nGrille compl\x8ate !\n\n");
    system("pause");
    printf("\n");
}

void afficher_grille(int taille,int *grille, int indice){
    // nombre de lignes nécessaires à l'affichage
    int nbr_lignes = sqrt(taille) * 2;
    taille = sqrt(taille) / 2;
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
            for (int j = taille * i; j <  taille * i + nbr_lignes / 2; j++){
                if (grille[j] == 3)
                    printf("    \xb3");
                else {
                    if (j == indice)
                        textcolor(RED);
                    printf("  %d", grille[j]);
                    textcolor(WHITE);
                    printf(" \xb3");
                }
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
    if (ligne < 1 || ligne > 8)
        return false;
    if (taille == 16 && ligne > 4)
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

bool grille_complete(int taille, int *grille_jeu){
    for (int i = 0; i < taille; i++) {
        if (grille_jeu[i] == 3)
            return false;
    }
    return true;
}

/// Vérification

bool verif_reponse(int *grille_jeu, int indice, int taille, int reponse, bool jouer){
    int grille_test[taille];
    for (int i = 0; i < taille; i ++)
        grille_test[i] = grille_jeu[i];
    grille_test[indice] = reponse;
    bool verif = true;
    verif_ligne(grille_test, taille, &verif, jouer);
    verif_colonne(grille_test, taille, &verif, jouer);
    return verif;
}

void verif_ligne(int *grille_test, int taille, bool *verif, bool jouer){
    taille = sqrt(taille);
    int cpt0 = 0, cpt1 = 0;
    int sim1 = 0, sim2 = 0, sim3 = 0, sim4 = 0, sim5 = 0, sim6 = 0, sim7 = 0;
    while (*verif) {
        for (int i = 0; i < taille; i++) {
            for (int j = 0; j < taille; j++) {
            // 0 et 1 d'affilés
                if (j < taille - 2 && *verif)
                    if (grille_test[i * taille + j] == grille_test[i * taille + j + 1] && grille_test[i * taille + j] == grille_test[i * taille + j + 2] && grille_test[i * taille + j] != 3){
                        *verif = false;
                        if(jouer) {
                            textcolor(RED);
                            printf("\nCoup non valide : il ne peut y avoir seulement deux caract\x8ares identiques d'affil\x82\n");
                            textcolor(WHITE);
                        }
                        break;
                    }
            // nombre de 0 ou de 1 par ligne
                if (grille_test[i * taille + j] == 0)
                    cpt0++;
                else if (grille_test[i * taille + j] == 1)
                    cpt1++;
                if (cpt0 > taille / 2 || cpt1 > taille / 2 && *verif) {
                    *verif = false;
                    if(jouer) {
                        textcolor(RED);
                        printf("\nCoup non valide : le nombre de 0 ou de 1 est sup\x82rieur \x85 %d sur la ligne\n",
                               taille / 2);
                        textcolor(WHITE);
                    }
                    break;
                }
            // lignes identiques
                for (int k = i + 1; k < taille; k++){
                    if (grille_test[i * taille + j] == grille_test[k * taille + j] && grille_test[i * taille + j] != 3) {
                        if (k == 1)
                            sim1 ++;
                        else if (k == 2)
                            sim2 ++;
                        else if (k == 3)
                            sim3 ++;
                        else if (k == 4)
                            sim4 ++;
                        else if (k == 5)
                            sim5 ++;
                        else if (k == 6)
                            sim6 ++;
                        else if (k == 7)
                            sim7 ++;
                    }
                }
            }

            if (sim1 >= taille -2|| sim2 >= taille-2 || sim3 >= taille -2|| sim4 >= taille-2 || sim5 >= taille-2 || sim6 >= taille -2|| sim7 >= taille -2 && *verif){
                *verif = false;
                if(jouer) {
                    textcolor(RED);
                    printf("\nCoup non valide : deux lignes sont identiques\n");
                    textcolor(WHITE);
                }
            }
            cpt0 = cpt1 = 0;
            sim1 = sim2 = sim3 = sim4 = sim5 = sim6 = sim7 = 0;
        }
        break;
    }
}

void verif_colonne(int *grille_test, int taille, bool *verif, bool jouer){
    taille = sqrt(taille);
    int cpt0 = 0,  cpt1 = 0;
    int sim1 = 0, sim2 = 0, sim3 = 0, sim4 = 0, sim5 = 0, sim6 = 0, sim7 = 0;
    while (*verif) {
        for (int i = 0; i < taille; i++) {
            for (int j = i; j < taille * taille; j +=taille){
                //0 et 1 d'affilé
                if(i < taille-2 && verif)
                    if(grille_test[i*taille+j] == grille_test[(i+1)*taille+j] && grille_test[i*taille+j] == grille_test[(i+2)*taille+j] && grille_test[i * taille + j] != 3){
                        *verif = false;
                        if(jouer) {
                            textcolor(RED);
                            printf("\nCoup non valide : il ne peut y avoir seulement deux caract\x8ares identiques d'affil\x82\n");
                            textcolor(WHITE);
                        }
                        break;
                    }
                // nombre de 0 et de 1 par colone
                if (grille_test[j] == 0)
                    cpt0++;
                else if (grille_test[j] == 1)
                    cpt1++;
                if (cpt0 > taille / 2 || cpt1 > taille / 2) {
                    *verif = false;
                    if(jouer) {
                        textcolor(RED);
                        printf("\nCoup non valide : le nombre de 0 ou de 1 est sup\x82rieur \x85 %d dans la colonne\n",
                               taille / 2);
                        textcolor(WHITE);
                    }
                    break;
                }
                //colone identiques
                for (int k = j + 1; k < taille; k++){
                    if (grille_test[i * taille + j] == grille_test[i * taille + k] && grille_test[i * taille + j] != 3) {
                        if (k == 1)
                            sim1 ++;
                        else if (k == 2)
                            sim2 ++;
                        else if (k == 3)
                            sim3 ++;
                        else if (k == 4)
                            sim4 ++;
                        else if (k == 5)
                            sim5 ++;
                        else if (k == 6)
                            sim6 ++;
                        else if (k == 7)
                            sim7 ++;
                    }
                }

            }
            if (sim1 >= taille -2|| sim2 >= taille-2 || sim3 >= taille -2|| sim4 >= taille-2 || sim5 >= taille-2 || sim6 >= taille -2|| sim7 >= taille -2 && *verif){
                *verif = false;
                if(jouer) {
                    textcolor(RED);
                    printf("\nCoup non valide : deux colones sont identiques\n");
                    textcolor(WHITE);
                }
            }
            cpt0 = cpt1 = 0;
            sim1 = sim2 = sim3 = sim4 = sim5 = sim6 = sim7 = 0;
        }
        break;
    }
}