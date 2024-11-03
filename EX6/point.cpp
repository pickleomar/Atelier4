// point.cpp
#include <iostream>
#include "point.h"
using namespace std;

// Implémentation du constructeur
Point::Point(float abs, float ord) : x(abs), y(ord) {
}

// Implémentation de la fonction deplace
void Point::deplace(float dx, float dy) {
    x += dx;
    y += dy;
}

// Implémentation de la fonction affiche
void Point::affiche() const {
    cout << "Point(" << x << ", " << y << ")" << endl;
}

// Implémentation des accesseurs
float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}