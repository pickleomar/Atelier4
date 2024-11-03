#include <iostream>
using namespace std;

class Test {
private:
    static int compteur;

public:
    Test() {
        cout << "Construction d'un objet Test" << endl;
    }

    void call() {
        compteur++;
        cout << "Appel numéro " << compteur << " de la fonction call()" << endl;
    }


    static int getNombreAppels() {
        return compteur;
    }

    ~Test() {
        cout << "Destruction d'un objet Test" << endl;
    }
};


int Test::compteur = 0;

int main() {
    cout << "=== Test du compteur d'appels ===" << endl << endl;

    // Création d'un objet Test
    Test test1;
    cout << "Appels avec test1:" << endl;
    test1.call();
    test1.call();
    test1.call();

    cout << "\nCréation d'un deuxième objet Test" << endl;
    Test test2;
    cout << "Appels avec test2:" << endl;
    test2.call();
    test2.call();

    cout << "\nRetour à test1:" << endl;
    test1.call();

    // Affichage du nombre total d'appels
    cout << "\nNombre total d'appels à la fonction call(): "
         << Test::getNombreAppels() << endl;

    return 0;
}
