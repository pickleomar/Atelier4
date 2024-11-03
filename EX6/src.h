// point.h
#ifndef POINT_H
#define POINT_H

class Point {
private:
    float x;
    float y;

public:
    // Constructeur
    Point(float x = 0, float f = 0);

    // Fonction de déplacement
    void deplace(float dx, float dy);

    // Fonction d'affichage
    void affiche() const;

    // Accesseurs (getters)
    float getX() const;
    float getY() const;
};

#endif