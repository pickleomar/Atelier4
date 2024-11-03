#include <iostream> 
using namespace std;
struct element {
    int valeur;
    element* suivant;
    element(int val) : valeur(val), suivant(nullptr) {}
};

class liste {
private:
    element* premier;  // Pointeur sur le premier élément

public:
    // Constructeur
    liste() : premier(nullptr) {}
    
    // Destructeur pour éviter les fuites mémoire
    ~liste() {
        while (premier != nullptr) {
            element* temp = premier;
            premier = premier->suivant;
            delete temp;
        }
    }
    // Méthode pour ajouter un élément au début de la liste
    void ajouter(int valeur) {
        element* nouvel_element = new element(valeur);
        nouvel_element->suivant = premier;
        premier = nouvel_element;
    }
    // Méthode pour supprimer le premier élément
    void supprimer() {
        if (premier != nullptr) {
            element* temp = premier;
            premier = premier->suivant;
            delete temp;
        }
    }
    // Méthode pour afficher la liste
    void afficher() const {
        element* courant = premier;
        while (courant != nullptr) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }
        cout << endl;
    }
};
