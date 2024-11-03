#include <iostream>
#include <cmath>
using namespace std;

class vecteur3d {
private:
    float x, y, z;

public:
    //Constructeur avec valeurs par défaut
    vecteur3d(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    // Fonction d'affichage
    void afficher() const {
        cout << "("<<x<<", "<<y<<", "<<z<<")"<< endl;
    }


    vecteur3d somme(const vecteur3d& v) const {
        return vecteur3d(x + v.x,y + v.y,z + v.z);
    }

    vecteur3d* sommeAddr(const vecteur3d* v) const {
        vecteur3d* resultat = new vecteur3d(x+v->x,y + v->y,z +v->z);
        return resultat;
    }


    vecteur3d& somme_Ref(const vecteur3d& v, vecteur3d& resultat) const {
        resultat.x = x + v.x;
        resultat.y = y + v.y;
        resultat.z = z + v.z;
        return resultat;
    }

    float produitScalaire(const vecteur3d& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    // Vérifier si deux vecteurs ont les mêmes composantes
    bool coincide(const vecteur3d& v) const {
        return (x == v.x && y == v.y && z == v.z);
    }
    // Calcule de la norme du vecteur
    float norme() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Retourne le vecteur avec la plus grande norme
    const vecteur3d& normax(const vecteur3d& v) const {
        if (this->norme() >= v.norme())
            return *this;
        return v;
    }
    // Accesseurs (getters)
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }
};

int main() {
    cout << "=== Test de la classe vecteur3d ===" << endl << endl;

    // Création de vecteurs
    vecteur3d v1(1, 2, 3);
    vecteur3d v2(4, 5, 6);
    vecteur3d v3; // Vecteur nul par défaut

    // Test d'affichage
    cout << "v1 = "; v1.afficher();
    cout << "v2 = "; v2.afficher();
    cout << "v3 = "; v3.afficher();
    cout << endl;

    // Test de la somme (par valeur)
    cout << "Somme (par valeur) de v1 et v2 = ";
    vecteur3d somme = v1.somme(v2);
    somme.afficher();

    // Test de la somme (par adresse)
    cout << "Somme (par adresse) de v1 et v2 = ";
    vecteur3d* sommePtr = v1.sommeAddr(&v2);
    sommePtr->afficher();
    delete sommePtr; // Libération de la mémoire

    // Test de la somme (par référence)
    cout << "Somme (par référence) de v1 et v2 = ";
    vecteur3d resultat;
    v1.somme_Ref(v2, resultat);
    resultat.afficher();

    // Test du produit scalaire
    cout << "Produit scalaire de v1 et v2 = "
         << v1.produitScalaire(v2) << endl;

    // Test de coïncidence
    cout << "v1 et v2 coïncident ? "
         << (v1.coincide(v2) ? "Oui" : "Non") << endl;

    // Test des normes
    cout << "Norme de v1 = " << v1.norme() << endl;
    cout << "Norme de v2 = " << v2.norme() << endl;

    // Test de normax
    cout << "Vecteur avec la plus grande norme entre v1 et v2 = ";
    v1.normax(v2).afficher();

    return 0;
}
