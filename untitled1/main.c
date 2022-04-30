#include <stdio.h>
int main() {
    int exo;
    printf("Quel exercice voulez-vous exécuter ?\n");
    scanf("%d", &exo);
    switch (exo)
    {
        case 1:
        {
            printf("*************\n");
            printf("*    Test   *\n");
            printf("*************");
            break;
        }
        case 2:
        {
            printf("1- Saisie des données\n2- Traitement des données\n3- Affichage des résultats\n4- Quitter");
            break;
        }
        case 3:
        {
            int valeur1, valeur2, valeur3 ;
            printf("Merci de saisir la première valeur : ");
            scanf("%d", &valeur1);
            printf("La première valeur saisie = %d\n", valeur1);
            printf("Merci de saisir la deuxième valeur : ");
            scanf("%d", &valeur2);
            printf("La deuxième valeur saisie = %d\n", valeur2);
            printf("Merci de saisir la troisième valeur : ");
            scanf("%d", &valeur3);
            printf("La troisième valeur saisie = %d\n", valeur3);
            printf("""/*** \" c'est fini \" ***/""");
            break;
        }
        case 4:{
            char n;
            printf("Merci de saisir un premier caractère : ");
            scanf(" %c", &n);
            printf("Le caractère saisi est %c et son code ascii est %d", n, n);
            break;
        }
        case 5:{
            int a = 13;
            double y = 4;
            float b = 1567.23;
            float c = 12.12;
            float d = 123.4;
            float e = 0.3;
            printf("%7d \n", a);
            printf("%.2f \n", y);
            printf("%.2f \n", b);
            printf("%7.2f \n", c);
            printf("%7.2f \n", d);
            printf("%7.2f", e);
            break;
        }
        case 6:{
            int val1, val2, val3;
            printf("Saisir trois valeurs : ");
            scanf("%d, %d, %d", &val1, &val2, &val3);
            printf("La somme des trois valeurs est : %d", (val1 + val2 + val3));
            break;
        }
        case 7:{
            int a, c;
            char b;
            printf("Saisir une opération simple : \n");
            scanf("%d %c %d", &a, &b, &c);
            switch (b) {
                case '+': {
                    printf("%d %c %d = %d", a, b, c, (a + c));
                    break;
                }
                case '-':{
                    printf("%d %c %d = %d", a, b, c, (a - c));
                    break;
                }
                case '*':{
                    printf("%d %c %d = %d", a, b, c, (a * c));
                    break;
                }
                case '/':{
                    printf("%d %c %d = %d", a, b, c, (a / c));
                    break;
                }
                default: printf("Opérateur inconnu");
            }
            break;
        }
        case 8:{
            int h, m, s;
            do {
                printf("Saisir l'heure au format HH: MM: SS  : \n");
                scanf("%d : %d : %d", &h, &m, &s);
            }
            while (((h < 0) || (h > 23)) || ((m < 0) || (m > 59)) || ((s < 0) || (s > 59)));
            printf("Il est %d heures %d minutes et %d secondes", h, m, s);
            break;
        }
        default : printf("Ce numéro d'exercice n'existe pas. \n");
    }
    return 0;
}