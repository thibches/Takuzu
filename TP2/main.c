#include <stdio.h>
int main() {
    int exo;
    printf("Quel exercice voulez-vous exécuter ?\n");
    scanf("%d", &exo);
    switch (exo)
    {
        case 1:
        {
            int i, j;
            i = 0;
            while (i < 11)
            {
                printf("******\n");
                i+=4;
            }
            printf("i = %d\n\n", i);


            for (j = 7;j > 0; j -= 2)
            {
                printf("******\n");
            }
            printf("j = %d\n\n", j);


            for (i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("******\n");
                }
            }
            printf("\n\n");


            for (i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("**");
                }
                printf("\n");
            }
            printf("\n\n");


            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 3; j++)
                {}
            }
            printf("i = %d ****** j = %d", i, j);


            break;
        }
        case 2:
        {
// exemple de code exercice 2
            double y = 3.5643;
            printf("%d \n", (int)y);
            break;
        }
        default : printf("Ce numéro d'exercice n'existe pas. \n");
    }
    return 0;
}