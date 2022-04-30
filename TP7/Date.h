//
// Created by chesn on 18/03/2022.
//

#ifndef TP7_DATE_H
#define TP7_DATE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int jour;
    int mois;
    int annee;
}DATE;
void lireDate(DATE*);
void afficherDate(DATE *);
int comparerDates(DATE*, DATE*);



#endif //TP7_DATE_H
