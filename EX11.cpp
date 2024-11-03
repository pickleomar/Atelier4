#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Traitement {
private:
    vector<int> vecteur;

public:
    void Initialiser() {
        int nombre;
        vecteur.clear();

        for (int i = 0; i < 15; ++i) {
            cout << "Entrez un entier pair non nul : ";
            cin >> nombre;

            if (cin.fail() || nombre % 2 != 0 || nombre == 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Erreur : veuillez entrer un entier pair non nul." << endl;
                --i;
            } else {
                vecteur.push_back(nombre);
            }
        }
    }

    void show(int index = 0) const {
        if (index < vecteur.size()) {
            cout << vecteur[index] << " ";
            show(index + 1);
        } else if (index == 0) {
            cout << "Le vecteur est vide." << endl;
        }
    }

    friend double moyenne(const Traitement& t) {
        if (t.vecteur.empty()) return 0.0;
        double somme = 0;
        for (int nombre : t.vecteur) {
            somme += nombre;
        }
        return somme / t.vecteur.size();
    }

    friend double mediane(Traitement& t) {
        if (t.vecteur.empty()) return 0.0;
        
        sort(t.vecteur.begin(), t.vecteur.end());
        int taille = t.vecteur.size();
        if (taille % 2 == 0) {
            return (t.vecteur[taille / 2 - 1] + t.vecteur[taille / 2]) / 2.0;
        } else {
            return t.vecteur[taille / 2];
        }
    }
};

int main() {
    Traitement t;
    t.Initialiser();
    cout << "Contenu du vecteur : ";
    t.show();
    cout << endl;
    cout << "Moyenne du vecteur : " << moyenne(t) << endl;
    cout << "Médiane du vecteur : " << mediane(t) << endl;

    return 0;
}
