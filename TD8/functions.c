//
// Created by chesn on 18/03/2022.
//

#include "functions.h"

int factorielle(int n){
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorielle(n - 1);
    }
} // EX1
int fibonacci_rec(int n){
    int res;
    if (n == 0)
    {
        res = 0;
    }
    else
    {
        if ( n == 1 )
        {
            res = 1;
        }
        else
        {
            res = fibonacci_rec(-- n) + fibonacci_rec(n - 1);
        }
    }
    return res;
} // EX2
int pgcd(int a, int b){
    int res;
    if (a > b)
    {
        res = pgcd(a - b, b);
    }
    else
    {
        if (a < b)
        {
            res = pgcd(a, b - a);
        }
        else
        {
            res = a;
        }
    }
    return res;
} // EX3
int puissance(int x, int n)
{
    if (n == 0)
        return 1;
    else
        return(x*puissance(x,n-1));
} // EX5
int nb_chiffre(int n)
{
    int res;
    if (n<10)
        return n;
    else{
        res = n % 10 + nb_chiffre(n / 10);
    }
    return res;
} // EX6
int somme_chiffres(int n)
{
    if (n<10){
        return n;
    }
    else
        return(somme_chiffres(n/ 10));
} // EX7
int somme_tab(int tab[], int taille)
{
    if (taille == 0)
        return(tab[0]);
    else
        return tab[taille]+somme_tab(tab,taille-1);
}
int somme_car(char* c){
    int res = 0;
    if (*c == ('\0')){
        return 0;
    }
    else{
        res = 1 + somme_car(c + 1);
    }
    return res;
} //EX8
