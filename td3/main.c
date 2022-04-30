#include <stdio.h>
#define TaillePhys 100
int main() {
     int exo;
     printf("Quel exercice voulez-vous exécuter ?\n");
     scanf("%d", &exo);
     switch (exo)
     {
         case 1:
         {
            int tab[TaillePhys];
            int Taille_utile, i, nep;
            do{
                printf("Donnez la taille utile :");
                scanf("%d", &Taille_utile);
            }while (Taille_utile < 1 || Taille_utile > 100);
            // Saisir les valeurs du tableau
            for (i=0;i < Taille_utile; i++){
                printf("Donner Tab[%d]:", i);
                scanf("%d", &tab[i]);
            }
            // Affichage des éléments des tableaux
            for (i=0; i < Taille_utile; i++){
                printf("%d\n", tab[i]);
            }
            // Calcul du nombre des éléments pairs et impairs
            nep=0;
            for (i = 0; i < Taille_utile; i++){
                if (tab[i] % 2 == 0){
                    nep++;
                }
            }

            // Afficher le nombre des élémentspairs et impairs
            printf("Le nombre d'éléments pairs = %d, le nombre d'éléments impairs = %d\n", nep, Taille_utile - nep);
            break;
         }
         case 2:
         {
             int TabA[TaillePhys];
             int Taille_utile, i;
             do{
                 printf("Donnez la taille utile : ");
                 scanf("%d", &Taille_utile);
             }while (Taille_utile < 1 || Taille_utile > 100);
             for (i = 0; i < Taille_utile; i++){
                 scanf("%d", TabA[i]);
             }
             break;
         }
         case 3:{
             float Tab[TaillePhys], max1, max2;
             int Taille_utile, i;
             do{
                 printf("Donner la taille utile : ");
                 scanf("%d", &Taille_utile);
             }while (Taille_utile < 1 || Taille_utile > 100);

             for(i=0; i < Taille_utile; i++){
                 printf("Donner Tab[%d] :", i);
                 scanf("%f", &Tab[i]);
             }

             for (i=0; i<Taille_utile; i++){
                 printf("%f\n", Tab[i]);
             }

             max1 = max2 = Tab[0];
             for (i=1; i < Taille_utile; i++){
                 if (Tab[i]>=max1){
                     max2 = max1;
                     max1 = Tab[i];
                 }
                 else if (Tab[i]>max2){
                     max2 = Tab[i];
                 }
             }
             printf("max1=%f\nmax2=%f\n", max1, max2);
             break;
         }
         case 4:{

            #define TailleLog 15
                             char c[TailleLog];
                             int i, cpt = 0;
                             printf("Saisir un mot : \n");
                             scanf("%s", c);
                             for (i=0; i < TailleLog; i++){
                                 if (c != "\0"){
                                     cpt++;
                                 }
                             }
                             break;
         }
         default : printf("Ce numéro d'exercice n'existe pas. \n");
     }
     return 0;
}