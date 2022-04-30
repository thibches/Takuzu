#include "functions.h"
#include <stdio.h>


int main (){
    int exo;
    printf("Saisir un numéro d'exercice :");
    scanf(" %d", &exo);

    switch (exo){
        case 1: {
            int N, fact ;
            printf("Saisir un entier N : \n") ;
            scanf(" %d", &N) ;
            fact = factorielle(N) ;
            printf("%d ! = %d", N, fact);
            break;
        }
        case 2: {
            int n, res;
            printf("Saisir un entier : \n");
            scanf(" %d", &n);
            res = fibonacci_rec(n);
            printf("La suite de fibonaci au %d ieme terme est : %d ", n, res);
            break;
        }
        case 3: {
            int x, y, res;
            do
            {
                printf("Saisir deux entiers positifs séparés par un espace : \n") ;
                scanf(" %d %d", &x, &y) ;
            }
            while ( x < 0 && y < 0) ;
            res = pgcd(x, y) ;
            printf("Le pgcd de %d et %d est %d", x, y, res);
            break;
        }
        case 4:
        {
            int n,m;
            printf("entree des deux valeurs :");
            scanf(" %d, %d",&n, &m);
            printf("\n le resultat est : %d",puissance(n,m));
            break;
        }
        case 5:
        {
            int n,m;
            printf("entree des deux valeurs :");
            scanf(" %d",&n);
            printf("\n le resultat est : %d",nb_chiffre(n));
            break;
        }
        case 6: {
            int n,m;
            printf("entree des deux valeurs :");
            scanf(" %d",&n);
            printf("\n le resultat est : %d",somme_chiffres(n));
            break;
        }
        case 7:
        {
            int tab[] ={1,0,0,0,},n;
            printf("entree des deux valeurs :");
            scanf(" %d",&n);
            printf("\n le resultat est : %d",somme_tab(tab,n));
            break;
        }
        case 8:
        {
            int tab[] ={1,0,0,0,},n;
            printf("entree des deux valeurs :");
            scanf(" %d",&n);
            printf("\n le resultat est : %d",somme_tab(tab,n));
            break;
        }
        case 9:{
            int res = 0;
            char* chaine[100];
            printf("Saisir une chaine : \n");
            scanf(" %s", chaine);
            res = somme_car(chaine);
            printf("La somme des carcactères vaut : %d", res);
            break;
        }

        default :
            printf("Ce numéro d'exercice n'existe pas.\n");
    }
    return 0;
}
