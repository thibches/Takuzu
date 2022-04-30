//
// Created by chesn on 04/03/2022.
//

#include "TP5.h"

int minimum(int a, int b){
    if (a<b){
        return a;
    }
    else{
        return b;
    }
    // est éqivalent à : return(a<b ? a:b)
}
void min_max(int a, int b,int *min, int *max){
    if (a<b){
        *min = a;
        *max = b;
    }
    else{
        *min = b;
        *max = a;
    }

}
int somme_tab(int tab[], int TailleLog){
    int i, Somme = 0;
    for (i=0; i< TailleLog; i++){
        Somme += tab[i];
    }
    return Somme;
}
int ajouter_val_tab(int *tab, int TailleLog, int TaillePhys, int val){
    if ((TailleLog + 1) <= TaillePhys){
        tab[TailleLog] = val;
        return 1;
    }
    else{
        return 0;
    }
}
void crypter_chaine(char *ch){
    for (int i = 0; i < sizeof(ch) - 1;i++){
        ch[i] += 3;
    }
}
