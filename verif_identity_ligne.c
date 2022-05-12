void verif_identity_ligne(int *grille_test, int taille, bool *verif){
    taille = sqrt (taille);
    int ligne[4] = {};
    int ligne1[4] = {};
    int ligne2[4] = {};
    int ligne3[4] = {};
    while(*verif){
        for (int i = 0; i < taille; i++){
            ligne = [i++];
            for (int k = 3; k < taille; k++){
                ligne1 = [k++];
                for (int j = 7; j < taille; j++){
                    ligne2 = [j++];
                    for (int h = 11; h < taille; h++){
                        ligne3 = [h++];
                        if (ligne == ligne1 || ligne == ligne2 || ligne == ligne3 ){
                            if (ligne1 == ligne || ligne1 == ligne2 || ligne1 == ligne3){
                                if (ligne2 == ligne || ligne2 == ligne1 || ligne2 == ligne3){
                                    if (ligne3 == ligne || ligne3 == ligne1 || ligne3 == ligne2){
                                        *verif = false;


                                    break;
                                    }
                                }
                            }
                        }
                    }
                }

            }


        }

    }


}
