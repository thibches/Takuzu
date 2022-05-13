#include "Fonctions.h"

int main(){
    srand(time(NULL)); //pour générer nombres aléatoires
    int choix; // variable pour naviguer dans les menus
    menu_principal(&choix); // affichage menu pricipal
    return 0;
}
