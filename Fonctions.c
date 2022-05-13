//
// Created by chesn on 30/04/2022.
//

#include "Fonctions.h"

/// Menus
void menu_principal(int* choix){
    // boucle pour choix sécurisé
    do {
        // mise a 0 du choix
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
            // résolution de la grille
            resoudre(taille, grille_jeu);
            //retour menu quand grille finie
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
        // mise a 0 de choix
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
            // initialisation des variables nécessaires
            char colonne;
            int ligne;
            bool verif; // verifie les coordonnées
            bool masque = true; // verifie si continue a saisir la grille masque
            char c = '\x82'; //é
            do {
                // boucle de saisie sécurisée
                do {
                    //affichage interface
                    printf("\n***** Masque manuel *****\n\n");
                    afficher_grille(taille, grille_masque, -1);
                    printf("\n\nSaisir les coordonn%ces d'une case ou taper '00' pour retourner au menu jouer.\n"
                           "Saisie : ", c);
                    // récupération coordonnées
                    scanf(" %c %d", &colonne, &ligne);
                    // verifie si coordonnées valides
                    verif = verif_saisie(taille, colonne, ligne);
                    // message erreur si saisie incorect
                    if (verif != true) {
                        printf("\nErreur : saisie incorrect !\n");
                    }
                } while (verif != true);
                // convertie coordonnées en indice
                int indice = convertir_coordonnees(taille, colonne, ligne);
                int reponse; //reponse de l'utilisateur
                // boucle saicurisé pour réponse
                do {
                    fflush(stdin);
                    // affichage
                    printf("\nSaisir 0 (case invisible) ou 1 (case visible : ");
                    // recupération réponse
                    scanf(" %d", &reponse);
                    // message erreur si reponse différente de 0 ou 1
                    if (reponse != 0 && reponse != 1)
                        printf("\nErreur : saisie incorrecte\n");
                } while (reponse != 0 && reponse != 1);
                // assignation de la reponse a grille masque
                grille_masque[indice] = reponse;
                // boucle sécurisée continue saisir masque
                do{
                    // mise a 0 du choix
                    *choix = 0;
                    fflush(stdin);
                    // affichage
                    printf("\n1. Continuer\n"
                           "2. Jouer\n"
                           "3. Retour\n"
                           "Choix : ");
                    // recupération dela reponse
                    scanf(" %d", choix);
                    // message erreur si choix incorrect
                    if (*choix < 0 || *choix > 3)
                        printf("\nErreur : saisie non valide");
                }while(*choix < 0 || *choix > 3);
                // selon choix
                switch (*choix) {
                    // continuer
                    case 1:
                        break;
                    // jouer
                    case 2:{
                        // création grille jeu
                        int *grille_jeu = generer_grille_jeu(taille, grille_solution, grille_masque);
                        // arret de modification masque
                        masque = false;
                        // jouer
                        jouer(taille, grille_solution, grille_jeu, choix);
                        break;
                    }
                    // quitter
                    case 3: {
                        // arret de modification masque
                        masque = false;
                        break;
                    }
                    // erreur inconue
                    default:{
                        // arret de modification masque
                        masque = false;
                        // message erreur
                        printf("\nErreur masque manuel.\n"
                               "Contactez les cr\x82taurs : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                    }
                }
            }while(masque == true);
            // retour menu
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
            // affichage
            printf("\n***** Masque automatique *****\n");
            afficher_grille(taille, grille_masque, -1);
            printf("\n\n");
            afficher_grille(taille, grille_jeu,-1);
            // boucle choix sécurisée
            do{
                // choix remis a 0
                *choix = 0;
                fflush(stdin);
                // affichage
                printf("\n\n1. Jouer\n"
                       "2. Retour\n"
                       "Saisie : ");
                // recupération choix
                scanf(" %d", choix);
                //erreur si choix incorrect
                if (*choix != 1 && *choix != 2)
                    printf("Erreur : saisie non valide");
            }while (*choix != 1 && *choix != 2);
            // choix = jouer
            if (*choix == 1)
                jouer(taille, grille_solution, grille_jeu, choix);
            // choix retour
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
            // retour menu
            menu_principal(choix);
            break;
        }
        // Retour menu jouer si erreur inconnue
        default:{
            printf("\nErreur menu jouer.\n"
                   "Contactez les cr\x82taurs : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
        }
    }
    // retour menu
    menu_jouer(choix);
}

/// Grilles
void choix_taille(int* taille, int *choix){
    // boucle pour choix sécurisé
    do {
        // mise a 0 du choix
        *choix = 0;
        fflush(stdin);
        // affichage
        printf("\n***** Taille *****\n"
               "  1. 4x4\n"
               "  2. 8x8\n"
               "  3. Retour\n"
               "Choix :");
        // recuperation du choix
        scanf(" %d", choix);
        // erreur si choix invalide
        if (*choix < 1 || *choix > 3){
            printf("Erreur : choix non valide !");
        }
    }while (*choix < 1 || *choix > 3);
    // selon taille choisie
    switch (*choix){
        // choix : 4x4
        case 1:{
            // nbr de cases
            *taille = 16;
            break;
        }
        //choix : 8x8
        case 2:{
            //nbr de cases
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
            // erreur si fichier mal ouvert
            if (sp == NULL) {
                printf("\nErreur inconnue !\n"
                       "Contactez les Admins : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                menu_jouer(choix);
            }
            // compte le nombre de lignes du fichier
            int c; // ligne du fichier
            int nbr_lignes = 0; // nombre de lignes
            while ((c = fgetc(sp)) != EOF) {
                if (c == '\n') {
                    nbr_lignes++;
                }
            }
            // ajout dernier ligne
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
            // erreur si fichier mal ouvert
            if (sp == NULL) {
                printf("\nErreur inconnue !\n"
                       "Contactez les Admins : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                menu_jouer(choix);
            }
            // compte le nombre de lignes du fichier
            int c; // lignes du fichier
            int nbr_lignes = 0; // nombre de lignes
            while ((c = fgetc(sp)) != EOF) {
                if (c == '\n') {
                    nbr_lignes++;
                }
            }
            //ajout derniere ligne
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
            // erreur si fichier mal ouvert
            if (sp == NULL){
                printf("\nErreur inconnue !\n"
                       "Contactez les Admins : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                menu_jouer(choix);
            }
            // choix au hasard d'un numéro de ligne du fichier
            char numero_ligne[0];
            numero_grille_hasard(taille, numero_ligne,choix);
            // lecture du fichier jusqu'a ce que la ligne choisie soit trouvée
            bool verif_grille = false; // verification fin de ligne du fichier
            char solution[taille]; // lignes du fichier
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
            // erreur si fichier mal ouvert
            if (sp == NULL){
                printf("\nErreur inconnue !\n"
                       "Contactez les Admins : louis.geslin@efrei.net ou thibault.chesnel@efrei.net\n");
                menu_jouer(choix);            }
            // choix au hasard d'un numéro de ligne du fichier
            char numero_ligne[0];
            numero_grille_hasard(taille, numero_ligne,choix);
            char nbr_ligne = numero_ligne[0];//variable intermédiaire pour eviter bug
            char solution[taille];//lignes du fichier
            bool verif_grille = false;//verifie fin de ligne
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
    int case_visible = (taille / 2) - (taille / 8); //nombre de cases visibles
    for(int i=0; i < case_visible; i++) {
        int numero_case = rand() % taille;
        // verification que le numéro case n apas deja été choisi
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
        // cases invisibles
        if (grille_masque[i] == 0){
            grille_jeu[i] = 3;
        }
        // cases visibles
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
    bool resultat = true; // verifie si le jouer a perdue
    bool fait = false; // savoir si l'aide a été utilisée
    // boucle tant que grille pas finie
    do {
        do{
            // mise a 0 de choix
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
            //recuperation de choix
            scanf("%d", choix);
            //message erreur si choix incorrect
            if(*choix<1 || *choix>3){
                printf("\nErreur : choix non valide !\n");
            }
        } while (*choix<1 || *choix>3);
        // selon choix
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
    //afficher grille jeu
    afficher_grille(taille, grille_jeu,-1);
    // si joueur a gagné
    if (resultat)
        printf("\n\nF\x82licitation !\n");
    // si joueur a perdu
    else
        printf("\nPerdu ! Vous n'avez plus de vie.\n\n");
    // attend que le joueur agisse pour continuer
    system("pause");
    printf("\n");
}

void resoudre(int taille,int *grille_jeu){
    char c = '\x82'; //é
    taille = sqrt(taille); // taille sous forme AxA
    int lcpt0 = 0, lcpt1 = 0; // compteurs réponses lignes
    int ccpt0 = 0, ccpt1 = 0; // compteurs reponse colones
    bool action = false; // verifie qu'une vérification est faite
    // affichage
    printf("\n");
    afficher_grille(taille*taille, grille_jeu,-1);
    printf("\n");
    // attend que le joueur agisse pour continuer
    system("pause");
    // tant que grille pas résolue
    do {
        // aucune action réalisée
        action = false;
        do {
            //aucune action réalisée
            action = false;
            // boucle pour lignes
            for (int i = 0; i < taille; i++) {
                // mise a 0 des compteurs
                ccpt0 = ccpt1 = lcpt0 = lcpt1 = 0;
                // boucle des colonnes
                for (int j = 0; j < taille; j++) {
                    // devant 0 ou 1 d'affilées lignes
                    if (j > 0 && j < taille - 1) {// verifie qu on reste dans la ligne
                        // compare case avec suivante / verifie case précédente vide / verifie case pas vide
                        if (grille_jeu[i * taille + j] == grille_jeu[i * taille + j + 1] &&
                            grille_jeu[i * taille + j - 1] == 3 && grille_jeu[i * taille + j] != 3) {
                            // case précédente = 1 si case + 0
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[i * taille + j - 1] = 1;
                                // case précédente = 0 si case = 1
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[i * taille + j - 1] = 0;
                            // justification
                            printf("\n\nCar il ne peut y avoir seulement deux %d d'affil\x82\n\n",
                                   grille_jeu[i * taille + j]);
                            action = true;// action réalisée
                            afficher_grille(taille * taille, grille_jeu, i * taille + j - 1);//affichage
                            system("pause");// attend que le joueur agisse pour continuer
                        }
                    }
                    // derriere 0 ou 1 d'affilés lignes
                    if (j < taille - 2) {//verifie sort pas de ligne
                        //compare case avec case suivante / case suivante suivante est vide / case est pas vide
                        if (grille_jeu[i * taille + j] == grille_jeu[i * taille + j + 1] &&
                            grille_jeu[i * taille + j + 2] == 3 && grille_jeu[i * taille + j] != 3) {
                            // si case = 0 case suivante suivante + 1
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[i * taille + j + 2] = 1;
                            // si case = 1 case suivante suivante + 0
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[i * taille + j + 2] = 0;
                            // justification
                            printf("\n\nCar il ne peut y avoir seulement deux %d d'affil\x82\n\n",
                                   grille_jeu[i * taille + j]);
                            action = true; // action réalisée
                            afficher_grille(taille * taille, grille_jeu, i * taille + j + 2);// affichage
                            printf("\n");
                            system("pause");// attend que le joueur agisse pour continuer
                        }
                    }
                    // dessus 0 ou 1 d'affilés colones
                    if (i > 0 && i < taille - 1) { // verifie sort pas colonne
                        // compare case avec case dessous / case dessus vide / case pas vide
                        if (grille_jeu[i * taille + j] == grille_jeu[(i + 1) * taille + j] &&
                            grille_jeu[(i - 1) * taille + j] == 3 && grille_jeu[(i) * taille + j] != 3) {
                            // si case = 0 case dessus = 1
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[(i - 1) * taille + j] = 1;
                            // si case + 1 case dessu = 0
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[(i - 1) * taille + j] = 0;
                            // justification
                            printf("\n\nCar il ne peut y avoir seulement deux %d d'affil\x82\n\n",
                                   grille_jeu[i * taille + j]);
                            action = true;//action réalisée
                            afficher_grille(taille * taille, grille_jeu, (i - 1) * taille + j);// affichage
                            printf("\n");
                            // attend que le joueur agisse pour continuer
                            system("pause");
                        }
                    }
                    // dessous 0 ou 1 d'affilés colones
                    if (i < taille - 2) { // verifie sort pas de colone
                        // compare case avec case dessous / case dessous dessous vide / case pas vide
                        if (grille_jeu[i * taille + j] == grille_jeu[(i + 1) * taille + j] &&
                            grille_jeu[(i + 2) * taille + j] == 3 && grille_jeu[(i) * taille + j] != 3) {
                            // si case = 0 case dessous dessous = 1
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[(i + 2) * taille + j] = 1;
                            // si case + 1 case dessous dessous = 0
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[(i + 2) * taille + j] = 0;
                            // justification
                            printf("\n\nCar il ne peut y avoir seulement deux %d d'affil\x82\n\n",
                                   grille_jeu[i * taille + j]);
                            action = true;// action réalisée
                            afficher_grille(taille * taille, grille_jeu, (i + 2) * taille + j);// affichage
                            printf("\n");
                            system("pause");// attend que le joueur agisse pour continuer
                        }
                    }
                    // entre deux valeurs identiques lignes
                    if (j < taille - 2) { // verifie sort pas de ligne
                        // compare case avec case suivante suivante / case suivante vie / case pas vide
                        if (grille_jeu[i * taille + j] == grille_jeu[i * taille + j + 2] &&
                            grille_jeu[i * taille + j + 1] == 3 && grille_jeu[i * taille + j] != 3) {
                            // si case = 0 case suvante = 1
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[i * taille + j + 1] = 1;
                            // si case = 1 case suivante = 0
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[i * taille + j + 1] = 0;
                            // justification
                            printf("\n\nCar il ne peut y avoir seulement un %d entre deux %d\n\n",
                                   grille_jeu[i * taille + j + 1], grille_jeu[i * taille + j]);
                            action = true;// action réalisée
                            afficher_grille(taille * taille, grille_jeu, i * taille + j + 1);// affichage
                            printf("\n");
                            system("pause");// attend que le joueur agisse pour continuer
                        }
                    }
                    // entre deux valeurs identiques colones
                    if (i < taille - 2) { // verifie sort pas colone
                        // compare case avec case dessous dessous / case dessous vide / case pas vide
                        if (grille_jeu[i * taille + j] == grille_jeu[(i + 2) * taille + j] &&
                            grille_jeu[(i + 1) * taille + j] == 3 && grille_jeu[i * taille + j] != 3) {
                            // si case = 0 case dessou = 1
                            if (grille_jeu[i * taille + j] == 0)
                                grille_jeu[(i + 1) * taille + j] = 1;
                            // si case = 1 case dessou = 0
                            else if (grille_jeu[i * taille + j] == 1)
                                grille_jeu[(i + 1) * taille + j] = 0;
                            // justification
                            printf("\n\nCar il ne peut y avoir seulement un %d entre deux %d\n\n",
                                   grille_jeu[(i + 1) * taille + j], grille_jeu[i * taille + j]);
                            action = true;// action réalisée
                            afficher_grille(taille * taille, grille_jeu, (i + 1) * taille + j);// affichage
                            printf("\n");
                            system("pause");// attend que le joueur agisse pour continuer
                        }
                    }
                    // si grille a deja nombre max d une valeure lignes
                    if (grille_jeu[i * taille + j] == 0) // compte le nombre de 0 par ligne
                        lcpt0++;
                    else if (grille_jeu[i * taille + j] == 1) // compte le nombre de 1 par ligne
                        lcpt1++;
                    if (lcpt0 == taille / 2 || lcpt1 == taille / 2) { // si nombre max de 0 ou 1 par ligne
                        // remplie les cases vides
                        for (int k = 0; k < taille; k++) {
                            if (grille_jeu[i * taille + k] == 3) {
                                // mets un 0
                                if (lcpt0==taille/2)
                                    grille_jeu[i * taille + k] = 1;
                                // mets un 1
                                else
                                    grille_jeu[i * taille + k] = 0;
                                // justification
                                printf("\n\nCar il y a %d valeurs oppos%ces dans la ligne\n\n", taille / 2, c);
                                action = true; // action réalisée
                                afficher_grille(taille * taille, grille_jeu,i * taille + k); //affichage
                                printf("\n");
                                system("pause");// attend que le joueur agisse pour continuer
                            }
                        }
                    }
                    // si grille a deja nombre max d une valeure colones
                    if (grille_jeu[j * taille + i] == 0)// compte le nombre de0 par colone
                        ccpt0++;
                    else if (grille_jeu[j * taille + i] == 1)// compte l nombre de 1 par colone
                        ccpt1++;
                    if (ccpt0 == taille / 2 || ccpt1 == taille / 2) { // si nobre max de 0 ou 1 par colone
                        // remplissage case vide
                        for (int k = 0; k < taille; k++) {
                            if (grille_jeu[k * taille + i] == 3) {
                                // mets 1
                                if (ccpt0==taille/2)
                                    grille_jeu[k * taille + i] = 1;
                                //mets 0
                                else
                                    grille_jeu[k * taille + i] = 0;
                                //justification
                                printf("\n\nCar il y a %d valeurs oppos%ces dans la colone\n\n", taille / 2, c);
                                action = true;// action réalisée
                                afficher_grille(taille * taille, grille_jeu,k * taille + i);// affichage
                                printf("\n");
                                system("pause");// attend que le joueur agisse pour continuer
                            }
                        }
                    }
                }

            }
        }while(action == true);//tant qu une action est réalisée
        // Ajout réponse par supposition lorsque les astuces ne fonctionnent plus
        bool supposition = false;// action remise a 0
        for (int i = 0; i < taille; i++)
            for (int j = 0; j < taille; j++)
                if(grille_jeu[i*taille+j] == 3 && supposition == false){ // verifie case vide et action pas réalisée
                    if (verif_reponse(grille_jeu, i*taille+j, taille*taille, 0, false) == true) { // verifie si 0 est bonne réponse
                        grille_jeu[i * taille + j] = 0; // case vide = 0
                        // justification
                        printf("\n\nAjout d'un %d par supposition\n\n", grille_jeu[i * taille + j]);
                        afficher_grille(taille * taille, grille_jeu,i * taille + j);// affichage
                        printf("\n");
                        system("pause");// attend que le joueur agisse pour continuer
                    }
                    else { // 0 n est pas bonne réponse
                        grille_jeu[i * taille + j] = 1; // case vide = 1
                        // justification
                        printf("\n\nAjout d'un %d par supposition\n\n", grille_jeu[i * taille + j]);
                        afficher_grille(taille * taille, grille_jeu,i * taille + j); // affichage
                        printf("\n");
                        system("pause");// attend que le joueur agisse pour continuer
                    }
                    supposition = true; // action réalisée
                }
    }while(grille_complete(taille*taille, grille_jeu) == false); // tant que la grille est pas finie
    printf("\nGrille compl\x8ate !\n\n");// affichage
    system("pause");// attend que le joueur agisse pour continuer
    printf("\n");
}

void afficher_grille(int taille,int *grille, int indice){
    // nombre de lignes nécessaires à l'affichage
    int nbr_lignes = sqrt(taille) * 2;
    taille = sqrt(taille) / 2;
    // affichage haut de la grille
    if (nbr_lignes == 8)// si taille = 4
        printf("     A    B    C    D\n"
            "  \xda\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xbf");
    else // si taille = 8
        printf("     A    B    C    D    E    F    G    H\n"
               "  \xda\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xbf");
    int cpt =1; // numéroter les lignes
    for (int i = 0; i < nbr_lignes; i++) {
        if ((i == 0 || i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14) && i < nbr_lignes) {
            printf("\n%d \xb3", cpt);// affichage numéro ligne
            cpt++;
            for (int j = taille * i; j <  taille * i + nbr_lignes / 2; j++){
                if (grille[j] == 3)
                    printf("    \xb3");// affichage case vide
                else {
                    if (j == indice) // marque la case changée en rouge dans menu résoudre
                        textcolor(RED);
                    printf("  %d", grille[j]);// affichage case
                    textcolor(WHITE);//couleur par défaut
                    printf(" \xb3");
                }
            }
        }
        else if (nbr_lignes == 8){ // i taille == 4
            if (i == 7)
                printf("\n  \xc0\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xd9");//dernière ligne
            else
                printf("\n  \xc3\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xb4");//interlignes
        }
        else{ // si taille = 8
            if (i == 15)
                printf("\n  \xc0\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xd9");//dernière ligne
            else
                printf("\n  \xc3\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xb4");//interlignes
        }
    }
}

bool verif_saisie(int taille, char colonne, int ligne){
    // vérifie si coordonée colonne sont correctes pour grille de taille 8
    if(colonne != 'a' && colonne != 'b' && colonne != 'c' && colonne != 'd' && colonne != 'e' && colonne != 'f' && colonne != 'g' && colonne != 'h')
        if(colonne != 'A' && colonne != 'B' && colonne != 'C' && colonne != 'D' && colonne != 'E' && colonne != 'F' && colonne != 'G' && colonne != 'H')
            return false;//pas correct
        // verifie si coordonnées sont correct pour grille de taille 4
    if (taille == 16 && colonne != 'a' && colonne != 'b' && colonne != 'c' && colonne != 'd' && colonne != 'A' && colonne != 'B' && colonne != 'C' && colonne != 'D')
        return false;//pas correct
    // verifie si coordonées de lignes corretes pour grille de taille 8
    if (ligne < 1 || ligne > 8)
        return false;// pas correct
    // verifie si coordonnées de lignes correctes pour grille de taille 4
    if (taille == 16 && ligne > 4)
        return false;// pas correct
    return true;// correct
}

int convertir_coordonnees(int taille, char colonne, int ligne){
    taille = sqrt(taille);// taille sous forme AxA
    int cln = colonne;
    // change lettre minuscule en chiffre
    if (cln >= 97)
        cln -= 97;
    // change lettre majuscule en chiffre
    else
        cln -= 65;
    ligne -= 1; // car grille commence a 0 et pas 1
    return cln + ligne * taille; // retourne l'indice de la case correspondante aux coordonnées
}

bool grille_complete(int taille, int *grille_jeu){
    // vérifie si une grille est compléte
    for (int i = 0; i < taille; i++) {
        if (grille_jeu[i] == 3)
            return false;// grille incomplete
    }
    return true;//grille complete
}

/// Vérification

bool verif_reponse(int *grille_jeu, int indice, int taille, int reponse, bool jouer){
    // grille test = grille jeu plus réponse du joueur
    int grille_test[taille];
    // remplissage grille test
    for (int i = 0; i < taille; i ++)
        grille_test[i] = grille_jeu[i];
    // ajout de la reponse du joueur
    grille_test[indice] = reponse;
    bool verif = true;// vérifie si reponse est correcte
    verif_ligne(grille_test, taille, &verif, jouer);// verifie les lignes
    verif_colonne(grille_test, taille, &verif, jouer);// verifie les colonnes
    return verif;
}

void verif_ligne(int *grille_test, int taille, bool *verif, bool jouer){
    taille = sqrt(taille);// taille sus forme AxA
    int cpt0 = 0, cpt1 = 0;//compteurs de 0 et 1
    int sim1 = 0, sim2 = 0, sim3 = 0, sim4 = 0, sim5 = 0, sim6 = 0, sim7 = 0;// compteurs de similitudes
    while (*verif) { // tant que la réponse est juste
        // boucle lignes
        for (int i = 0; i < taille; i++) {
            // boucle colonnes
            for (int j = 0; j < taille; j++) {
                // 0 et 1 d'affilés
                if (j < taille - 2 && *verif) { // verifie sort pas de ligne
                    // compare case avec case suivante et case suivante suivante / case pas vide
                    if (grille_test[i * taille + j] == grille_test[i * taille + j + 1] &&
                        grille_test[i * taille + j] == grille_test[i * taille + j + 2] &&
                        grille_test[i * taille + j] != 3) {
                        *verif = false;//reponse fausse
                        if (jouer) {// affiche raison lorsque joueur joue
                            textcolor(RED);// texte rouge
                            // justification
                            printf("\nCoup non valide : il ne peut y avoir seulement deux caract\x8ares identiques d'affil\x82\n");
                            textcolor(WHITE);// couleur par défaut
                        }
                        break;
                    }
                }
                 // nombre de 0 ou de 1 par ligne
                if (grille_test[i * taille + j] == 0)// compte le nombre de 0 par ligne
                    cpt0++;
                else if (grille_test[i * taille + j] == 1)// compte le nombre de 1 par ligne
                    cpt1++;
                // si dépasse nombre max de 0 ou 1
                if (cpt0 > taille / 2 || cpt1 > taille / 2 && *verif) {
                    *verif = false; // reponse fausse
                    if(jouer) { //affichage justification quand joueur joue
                        textcolor(RED); // texte rouge
                        // justification
                        printf("\nCoup non valide : le nombre de 0 ou de 1 est sup\x82rieur \x85 %d sur la ligne\n",
                               taille / 2);
                        textcolor(WHITE);// couleur par défaut
                    }
                    break;
                }
                // lignes identiques
                for (int k = i + 1; k < taille; k++){ // parcours tt les lignes
                    // verifie similitude entre lignes / case pas vide
                    if (grille_test[i * taille + j] == grille_test[k * taille + j] && grille_test[i * taille + j] != 3) {
                        // ajoute 1 au compteur de similitude correspondant
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
            // si similitude max atteinte
            if (sim1 >= taille -2|| sim2 >= taille-2 || sim3 >= taille -2|| sim4 >= taille-2 || sim5 >= taille-2 || sim6 >= taille -2|| sim7 >= taille -2 && *verif){
                *verif = false; // réponse fausse
                if(jouer) { // affiche justification si joueur joue
                    textcolor(RED); // texte rouge
                    // justification
                    printf("\nCoup non valide : deux lignes sont identiques\n");
                    textcolor(WHITE);// couleur par défaut
                }
            }
            // remise a 0 des compteurs
            cpt0 = cpt1 = 0;
            sim1 = sim2 = sim3 = sim4 = sim5 = sim6 = sim7 = 0;
        }
        break;
    }
}

void verif_colonne(int *grille_test, int taille, bool *verif, bool jouer){
    taille = sqrt(taille);//taille sous forme AxA
    int cpt0 = 0,  cpt1 = 0; // compteurs de 0 et de 1;
    int sim1 = 0, sim2 = 0, sim3 = 0, sim4 = 0, sim5 = 0, sim6 = 0, sim7 = 0;//compteurs de similitudes
    while (*verif) { // tant que réponse vraie
        // boucle de colones
        for (int i = 0; i < taille; i++) {
            // boucle de lignes
            for (int j = i; j < taille * taille; j +=taille){
                //0 et 1 d'affilé
                if(i < taille-2 && verif) { // vérifie sort pas de colone
                    // compare case avec case dessous avec case dessous dessous / case pas vide
                    if (grille_test[i * taille + j] == grille_test[(i + 1) * taille + j] &&
                        grille_test[i * taille + j] == grille_test[(i + 2) * taille + j] &&
                        grille_test[i * taille + j] != 3) {
                        *verif = false;// reponse fausse
                        if (jouer) {// affiche justification si joueur joue
                            textcolor(RED);// texte rouge
                            printf("\nCoup non valide : il ne peut y avoir seulement deux caract\x8ares identiques d'affil\x82\n");// justification
                            textcolor(WHITE);// couleur par défaut
                        }
                        break;
                    }
                }
                // nombre de 0 et de 1 par colone
                if (grille_test[j] == 0)// compte le nombre de 0 par colone
                    cpt0++;
                else if (grille_test[j] == 1)// compte le nomobre de 1 par colone
                    cpt1++;
                // si nombre max de 0 ou 1 atteint
                if (cpt0 > taille / 2 || cpt1 > taille / 2) {
                    *verif = false;// réponse fausse
                    if(jouer) {// affiche justification si joueur joue
                        textcolor(RED);// texte rouge
                        printf("\nCoup non valide : le nombre de 0 ou de 1 est sup\x82rieur \x85 %d dans la colonne\n",
                               taille / 2);// justification
                        textcolor(WHITE);// couleur par défaut
                    }
                    break;
                }
                //colone identiques
                for (int k = j + 1; k < taille; k++){ //boucle pour parcourir tt les colones
                    // compare similitude entre colones / case pas vide
                    if (grille_test[i * taille + j] == grille_test[i * taille + k] && grille_test[i * taille + j] != 3) {
                        // ajoute 1 au compteur de similitude correspondant
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
            // si nombre de similitudes max atteint
            if (sim1 >= taille -2|| sim2 >= taille-2 || sim3 >= taille -2|| sim4 >= taille-2 || sim5 >= taille-2 || sim6 >= taille -2|| sim7 >= taille -2 && *verif){
                *verif = false; // réponse fausse
                if(jouer) {// affiche justification si joueur joue
                    textcolor(RED);// texte rouge
                    printf("\nCoup non valide : deux colones sont identiques\n");// jutsification
                    textcolor(WHITE);// couleur par défaut
                }
            }
            // remise à 0 des compteurs
            cpt0 = cpt1 = 0;
            sim1 = sim2 = sim3 = sim4 = sim5 = sim6 = sim7 = 0;
        }
        break;
    }
}