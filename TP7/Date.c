//
// Created by chesn on 18/03/2022.
//

#include "Date.h"

void lireDate(DATE* d) {
    printf("Saisir une date sous la forme jj/mm/aaaa : \n");
    scanf(" %d/%d/%d", &d->jour, &d->mois, &d->annee);
}

void afficherDate(DATE *d){
    printf("La date saisie est : %d/%d/%d\n", d->jour, d->mois, d->annee);
}

int comparerDates(DATE* d1, DATE* d2) {
    if (d1->annee > d2->annee) {
        return 1;
    } else {
        if (d1->annee < d2->annee) {
            return -1;
        } else {
            if (d1->mois > d2->mois) {
                return 1;
            } else {
                if (d1->mois < d2->mois) {
                    return -1;
                } else {
                    if (d1->jour > d2->jour) {
                        return 1;
                    } else {
                        if (d1->jour < d2->jour) {
                            return -1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
