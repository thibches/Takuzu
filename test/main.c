#include <stdio.h>
#include "functions.h"



int main(){
    int n, res;
    printf("Saisir un entier : \n");
    scanf(" %d", &n);
    res = fibonacci_rec(n);
    printf("La suite de fibonaci au %d ieme terme est : %d ", n, res);
    return 0;
}