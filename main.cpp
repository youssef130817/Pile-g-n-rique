#include <iostream>
#include "pile.h"
using namespace std;
int main() {
    // Exemple d'utilisation de la pile générique avec des entiers
    Pile<int> intPile;

    intPile.Empiler(1);
    intPile.Empiler(9);
    intPile.Empiler(8);
    intPile.Empiler(6);
    intPile.Empiler(11);
    intPile.Empiler(45);
    intPile.Empiler(-3);
    intPile.Empiler(7);
    intPile.Empiler(-9);

    intPile.Afficher();

    cout << endl;

    // Exemple d'utilisation de la pile générique avec des chaînes de caractères
    Pile<string > stringPile;
    stringPile.Empiler("generique");
    stringPile.Empiler("pile");
    stringPile.Empiler("une");
    stringPile.Empiler("suis");
    stringPile.Empiler("je");
    stringPile.Empiler("Bonjour");

   stringPile.Afficher();
    return 0;
}
