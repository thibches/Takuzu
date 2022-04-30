#include <stdio.h>
#define TailleLog 15

    char c[TailleLog];
    int i, cpt = 0;
    printf("Saisir un mot : \n");
    gets(c);
    for (i=0; i < TailleLog; i++){
        if (c != "\0"){
            cpt++;
        }
    }