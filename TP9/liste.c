//
// Created by chesn on 01/04/2022.
//

#include "liste.h"

MAILLON* creer_maillon(int val){
    MAILLON * new = (MAILLON*) malloc(sizeof (MAILLON));
    new->valeur = val;
    new->succ = NULL;
    return new;
}
bool liste_vide(LISTE L){
    if(L == NULL)
        return true;
    else
        return false;
}
LISTE ajouter_tete_liste(LISTE L, int val){
    if (liste_vide(L)){
        L = creer_maillon(val);
        return L;
    }
    else {
        LISTE temp = L;
        L = creer_maillon(val);
        L->succ = temp;
        return L;
    }
}
LISTE ajouter_queue_liste(LISTE L, int val){
    if (liste_vide(L)){
        L = creer_maillon(val);
    }
    else {
        LISTE temp = L;
        while (temp->succ != NULL) {
            temp = temp->succ;
        }
        temp->succ =creer_maillon(val);
    }
    return L;
}
int taille_liste(LISTE L){
    int taille = 0;
    if (liste_vide(L)){
        return taille;
    }
    else{
        taille = 1;
        while (L->succ != NULL) {
            taille += 1;
            L = L->succ;
        }
        return taille;
    }
}
void afficher_liste(LISTE L){
    if (taille_liste(L) == 0){
        printf("Liste vide\n");
    }
    else{
        while(L->succ != NULL){
            printf("%d", L->valeur);
            L = L->succ;
        }
        printf("%d\n", L->valeur);
    }
}
/*
LISTE creer_liste(int){

}
int somme_liste(LISTE){

}
int max_liste(LISTE){

}
int nombre_occurence_liste(LISTE, int){

}
LISTE concatener_deux_listes(LISTE, LISTE){

}
int* copier_liste_tab(LISTE){

}
*/
LISTE ajouter_milieu_liste(LISTE L, MAILLON* M, int val){
    if (M->succ == NULL){
        L = ajouter_queue_liste(L, val);
    }
    else{
        LISTE temp = M->succ;
        M->succ = creer_maillon(val);
        M = M->succ;
        M->succ = temp;
    }
    return L;
}
LISTE creer_liste_triee_croissant(int N){
    LISTE L=NULL;
    int val;
    for(int i =0; i < N; i++){
        LISTE temp = L;
        printf("Saisir la valeur %d/%d: \n", i+1, N);
        scanf("%d", &val);
        if (L==NULL){
            L = creer_maillon(val);
        }
        else{
            for(int j=0;j<i;j++) {
                if (temp->valeur < val) {
                    if (temp->succ == NULL) {
                        temp = ajouter_milieu_liste(L, temp, val);
                    } else {
                        temp = temp->succ;
                    }
                }
                else {
                    temp = ajouter_milieu_liste(L, temp, val);
                }
            }
            L = temp;
        }
    }
    return L;
}