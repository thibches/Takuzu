#include "liste.h"
#include <time.h>
int main() {
    int exo;
    srand(time(NULL));
    printf("Quel exercice voulez-vous exécuter ?\n");
    scanf("%d", &exo);
    switch (exo)
    {
        case 1:
        {
            int tab[] = {1, 2 , 3 , 4, 5, 6, 7, 8, 9, 10};
            LISTE L = NULL;
            for (int i = 0; i<5; i++){
                L = ajouter_queue_liste(L, tab[i]);
            }
          for (int i = 5; i <10; i++){
               L = ajouter_tete_liste(L, tab[i]);
            }
            printf("%d\n", taille_liste(L));
            afficher_liste(L);
            break;
        }
        case 2:
        {
            break;
        }
        case 4:{
            int tab[] = {1, 2 , 3 , 4, 5, 6, 7, 8, 9, 10};
            LISTE L = NULL;
            for (int i = 0; i<10; i++){
                L = ajouter_queue_liste(L, tab[i]);
            }
            afficher_liste(L);
            MAILLON *M = L;
            int val = rand()% taille_liste(L);
            for(int i = 0; i < val; i++){
                M = M->succ;
            }
            L = ajouter_milieu_liste(L, M, 11);
            afficher_liste(L);
            break;
        }
        case 5:{
            int N;
            printf("Saisir le nombrede valeurs :\n");
            scanf(" %d", &N);
            LISTE L = creer_liste_triee_croissant(N);
            afficher_liste(L);
            break;
        }
        default : printf("Ce numéro d'exercice n'existe pas. \n");
    }
    return 0;
}