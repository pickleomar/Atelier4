// main.cpp
#include <iostream>
#include "point.h"
using namespace std;

int main() {
    cout << "=== Test de la classe Point ===" << endl << endl;

    // Création d'un point
    Point p1(2.5, 3.7);
    cout << "Position initiale du point : ";
    p1.affiche();

    // Test de déplacement
    cout << "\nDéplacement du point de (1.2, -0.5)" << endl;
    p1.deplace(1.2, -0.5);
    cout << "Nouvelle position : ";
    p1.affiche();

    // Test avec un point par défaut
    cout << "\nCréation d'un point par défaut" << endl;
    Point p2;
    cout << "Position du second point : ";
    p2.affiche();

    // Test des accesseurs
    cout << "\nCoordonnées du premier point :" << endl;
    cout << "x = " << p1.getX() << endl;
    cout << "y = " << p1.getY() << endl;

    return 0;
}