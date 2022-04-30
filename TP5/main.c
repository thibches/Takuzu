#include "TP5.h"
#include "tableau.h"
int main (){
    int exo;
    printf("Saisir un numéro d'exercice :");
    scanf(" %d", &exo);

    switch (exo){
        case 1:{
            int x, y, min;
            printf("Saisir deux entiers séparés par un espace :");
            scanf(" %d %d", &x, &y);
            min = minimum(x, y);
            printf("Le minimum entre %d et %d est %d", x, y, min);
            break;
        }
        case 2:{
            int x, y, min=0, max=0;
            printf("Saisir deux entiers séparés par un espace :");
            scanf(" %d %d", &x, &y);
            min_max(x, y, &min, &max);
            printf("Le minimum est %d et le maximum est %d", min, max);
            break;
        }
        case 3:{
            int tab[] = {1 , 2 , 3 , 4 , 5};
            int TailleLog = 5, Somme;
            Somme = somme_tab(tab, TailleLog);
            printf("La somme des éléments du tableau est égale à %d", Somme);
            break;
            }
        case 4:{
#define TaillePhys 100
            int tab[TaillePhys];
            int TailleLog, val, verif, i;
            do{
                printf("Saisir le nombre de valeurs du tableau :");
                scanf(" %d", &TailleLog);
            }
            while (TailleLog > TaillePhys);
            for (i=0;i<TailleLog;i++){
                printf("Saisir la valeur %d du tableau : \n", i);
                scanf(" %d", &val);
                tab[i] = val;
            }
            printf("Saisir la valeur à ajouter : \n");
            scanf(" %d", &val);
            verif = ajouter_val_tab(&tab, TailleLog, TaillePhys, val);
            if (verif == 1){
                printf("Valeur ajoutée avec succes");
                for(i=0; i <= TailleLog; i++){
                    printf("%d ", tab[i]);
                }
            }
            else{
                printf("Valeur non ajoutée, tableau trop petit");
                for (i=0; i < TailleLog; i++){
                    printf("%d ", tab[i]);
                }
            }
            break;
        }
        case 5:{
            char ch[50];
            printf("Saisir une chaîne de cractère :");
            fflush(stdin);
            gets(ch);
            crypter_chaine(&ch);
            printf("%s", ch);
            break;
        }
        case 6:{
            int *tab;
            int size, somme;
            printf("Saisir le nombre de case du tableau : \n");
            scanf(" %d", &size);
            tab = create_tab(size);
            tab = fill_tab(tab, size);
            display_tab(tab, size);
            somme = sumtab(tab, size);
            printf("\nLa somme des valeurs du tableau est égale à : %d", somme);
            tab = ajouter_tab_val(tab, size);
            display_tab(tab, size + 1);
            break;
        }
        case 7:{

            break;
        }
        default :
            printf("Ce numéro d'exercice n'existe pas.\n");
    }
    return 0;
}