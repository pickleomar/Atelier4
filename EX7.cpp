#include <iostream>
using namespace std;

class Pile {
private:
    static const int MAX_SIZE = 100;
    int* elements;
    int sommet;
    int capacite;

public:
    // Constructeur par défaut
    Pile(int taille = MAX_SIZE) {
        capacite = taille;
        elements = new int[capacite];
        sommet = -1;  // Pile vide
        cout << "Création d'une pile de capacité " << capacite << endl;
    }

    Pile(const Pile& autre) {
        capacite = autre.capacite;
        sommet = autre.sommet;
        elements = new int[capacite];
        for(int i = 0; i <= sommet; i++) {
            elements[i] = autre.elements[i];
        }
        cout << "Copie d'une pile" << endl;
    }


    ~Pile() {
        delete[] elements;
        cout << "Destruction de la pile" << endl;
    }


    void push(int valeur) {
        if (sommet >= capacite - 1) {
            cout << "Erreur: La pile est pleine!" << endl;
            return;
        }
        elements[++sommet] = valeur;
        cout << "Push: " << valeur << endl;
    }


    int pop() {
        if (estVide()) {
            cout << "Erreur: La pile est vide!" << endl;
            return -1;
        }
        int valeur = elements[sommet--];
        cout << "Pop: " << valeur << endl;
        return valeur;
    }

    // Vérifier si la pile est vide
    bool estVide() const {
        return sommet == -1;
    }

    // Vérifier si la pile est pleine
    bool estPleine() const {
        return sommet == capacite - 1;
    }

    void afficher() const {
        if (estVide()) {
            cout << "La pile est vide" << endl;
            return;
        }
        cout << "Contenu de la pile (du sommet vers la base) : ";
        for (int i = sommet; i >= 0; i--) {
            cout << elements[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }

    // Obtenir la taille actuelle de la pile
    int taille() const {
        return sommet + 1;
    }
};

int main() {
    cout << "=== Test de la classe Pile ===" << endl << endl;

    cout << "Création et test de p1:" << endl;
    Pile p1(5);

    cout << "\nTest des opérations push sur p1:" << endl;
    p1.push(10);
    p1.push(20);
    p1.push(30);
    cout << "État actuel de p1:" << endl;
    p1.afficher();

    // Test avec la deuxième pile p2
    cout << "\nCréation et test de p2:" << endl;
    Pile p2(3);  // Pile de capacité 3

    p2.push(100);
    p2.push(200);
    cout << "État actuel de p2:" << endl;
    p2.afficher();

    // Test des opérations pop
    cout << "\nTest des opérations pop:" << endl;
    cout << "Pop sur p1:" << endl;
    p1.pop();
    p1.afficher();

    cout << "\nPop sur p2:" << endl;
    p2.pop();
    p2.afficher();

    // Test des cas limites
    cout << "\nTest des cas limites:" << endl;

    // Tester pile pleine
    cout << "Remplissage complet de p2 (capacité 3):" << endl;
    p2.push(300);
    p2.push(400);
    p2.push(500);

    // Tester pile vide
    cout << "\nVidage complet de p2:" << endl;
    p2.pop();
    p2.pop();
    p2.pop();
    p2.pop();  // Devrait afficher message d'erreur (pile vide)

    return 0;
}
