#include <stdio.h>

int main(){
    int op;
    printf("Saisir le numéro de l'exo : \n");
    scanf("%d", &op);
    switch (op){
        case 1: {
            int i = 0;
            while (i < 11)
            {
                i+=4;
                printf("******\n");
            }
            printf("\n");
            for (i = 7; i > 0; i -= 2)
            {
                printf("******\n");
            }
            printf("\n");
            for (i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {printf("******\n");}
            }
            printf("\n");
            for (i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {printf("**");}
                printf("\n");
            }
            printf("\n");
            int j;
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 3; j++)
                {printf("*");}
            }
            break;
        }
        case 2: {
            char car1, car2;
            int i, k;
            printf("Saisir un caractère : \n");
            scanf(" %c", &car1);
            printf("Saisir un autre caractère : \n");
            scanf( " %c", &car2);
            for (i=1 ; i < 6 ; i++){
                for (k=1 ; k < i * i +1 ; k++){
                    if (k % 2 == 0){
                        printf("%c ", car1);
                    }
                    else{
                        printf("%c ", car2);
                    }
                }
                printf("\n");
            }
            break;
        }
        case 3: {
            int a, b, r;
            printf("Saisir deux valeurs séparée par un espace : \n");
            scanf("%d %d, a, b");
            while (b != 0) {
                r = b - a * (b / a);
                a = b;
                b = r;
            }
            printf("le pgcd est %d", a);
            break;
        }
        case 4: {
            int a, b, i, res=0;
            printf("Saisir eux valeurs séparées par un espace : \n");
            scanf(" %d %d", &a, &b);
            for (i=0 ; i < b; i++){
                res += a;
            }
            printf("%d x %d = %d", a, b, res);
            break;
        }
        case 5: {
            int a,b,c,d;
            printf("Saisir un nombre a quatre chiffres avec un espace entre chacun d'eux : \n");
            scanf(" %d %d %d %d", &a,&b,&c,&d);
            break;
        }
        case 6: {
            int TabA[10], TabB[10], i;
            for(i=0; i<10;i++){
                printf("Saisir la valeur %d du tableau : \n", i);
                scanf(" %d", &TabA[i]);
            }
            for(i=0; i<10;i++) {
                TabB[i] = TabA[i];
            }
            break;
            }
        case 7: {
                int tab[3][3],i,j,v = 1;
                for (i=0;i<3;i++) {
                    for (j = 0; j < 3; j++) {
                        printf("Saisir valeur : \n");
                        scanf(" %d", &tab[i][j]);
                        if (tab[i][j] <= 9 && v != 0) {
                            v = 0;
                        }
                    }
                }
                if (v==1){
                    printf("Carré parfait");
                }
                else{
                    printf("Carré pas parfait");
                }
                break;
            }

            case 8:{
                int tab[5][5]={6,2,3,5,6,1,0,1,0,1,1,3,6,7,9,0,1,0,1,0,6,0,1,4,6};
                int sum = 0,i , j;
                for(i=0; i<5;i++){
                    printf("%.2f\n", i%2);
                    if(i%2){
                        printf("ok");
                        for(j=0;j<5;j++){
                            printf("%d\n", tab[i][j]);
                            sum += tab[i][j];
                        }
                    }
                }
                printf("%d", sum);
                break;
            }
            case 9:{
                int i;
                char str[] = "programme";
                i = 0;
                while (str[i+1] != '\0'){
                    printf("%c ", str[i]);
                    i++;
                }
                printf("\n");
                break;
            }
            case 10:{
#define LENGTH 20
                int i;
                char str[LENGTH] = "bcdef";
                i = 1;
                while (str[i] != '\0'){
                    if (i%2 == 1){
                        str[i] = str[i-1];
                    }
                    else{
                        str[i] = str[i] - 1;
                    }
                    i++;
                }
                printf("%s \n", str);
                break;
            }
            case 11:{
                char myStr[] = {'A', 'B', 'C', '\o', 'D'};
                printf("%s \n", myStr);
                break;
            }



        default:
            printf("Cet exo n'existe pas");
    }
    return 0;
}