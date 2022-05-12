void verif_identity_cln (int *grille_test, int taille, bool *verif) {
    taille = sqrt(taille);
    int cln[4] = {};
    while (*verif) {
        for (int i = 0; i < taille; i++) {
            for (int j = i; j < taille * taille; j += 4) {
                cln = [j++];
                if (cln == cln++){
                    *verif = false;
                    break;
                }

            }
        break;
        }
    }
}
