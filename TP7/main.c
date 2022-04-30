#include "classEtud.h"


int main (){
    int exo;
    printf("Saisir un numéro d'exercice :");
    scanf(" %d", &exo);

    switch (exo){
        case 1:{
            DATE d1, d2;
            int comp;
            lireDate(&d1);
            lireDate(&d2);
            afficherDate(&d1);
            afficherDate(&d2);
            comp = comparerDates(&d1, &d2);
            switch (comp) {
                case -1 : {
                    printf("La date 2 est plus récente\n");
                    break;
                }
                case 0:{
                    printf("Les dates sont égales\n");
                    break;
                }
                case 1:{
                    printf("La date 1 est plus récente\n");
                    break;
                }
            }
            break;
        }
        case 2:{
            ETUDIANT etudiant;
            lireEtudiant(&etudiant);
            afficherEtudiant(&etudiant);
            break;
        }
        case 3:{
            int N;
            ETUDIANT *T;
            printf("Saisir le nombre d'étudiant de la classe : \n");
            scanf(" %d", &N);
            lireTabEtudiants(&T, N);
            afficherTabEtudiants(T, N);
            break;
        }
        default :
            printf("Ce numéro d'exercice n'existe pas.\n");
    }
    return 0;
}
