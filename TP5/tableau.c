//
// Created by chesn on 11/03/2022.
//

#include "tableau.h"


int* create_tab(int size){
    int* tab;
    tab = (int*)calloc(size, sizeof(int));
    return tab;
}
int* fill_tab(int* tab, int size){
    for(int i = 0; i < size; i++){
        tab[i] = rand()%11;
    }
    return tab;
}
void display_tab(int* tab, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", tab[i]);
    }
}
int sumtab(int* tab, int size){
    int somme = 0;
    for(int i = 0; i < size; i++){
        somme += tab[i];
    }
    return somme;
}
int* ajouter_tab_val(int* tab, int size){
    int val;
    tab = realloc(tab, size + 1);
    printf("\nSaisir une valeur à ajouter au tableau : \n");
    scanf(" %d", &val);
    tab[size] = val;
    return tab;
}