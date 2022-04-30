//
// Created by chesn on 18/02/2022.
//
#include <stdio.h>
#include "TP4.h"
#define TailleLog 15
void exo1()
{
    char c[TailleLog];
    int i, cpt = 0;
    printf("Saisir un mot : \n");
    gets(c);
    for (i=0; i < TailleLog; i++){
        if (c != "\0"){
            cpt++;
        }
    }

}
void exo2()
{
    // Solution exo2 ici
}
// Suite des fonctions