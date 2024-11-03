#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

class Fichier {
private:
    char* P;         
    size_t longueur;  // Longueur en octets
    bool estCree;     // Flag pour vérifier si la mémoire est allouée

public:
    Fichier() : P(nullptr), longueur(0), estCree(false) {
        cout << "Construction d'un objet Fichier" << endl;
    }
    
    ~Fichier() {
        if (P != nullptr) {
            delete[] P;
            cout << "Libération de la mémoire" << endl;
        }
        cout << "Destruction de l'objet Fichier" << endl;
    }
    bool Creation(size_t taille) {
        if (estCree) {
            cout << "Erreur: Le fichier est déjà créé!" << endl;
            return false;
        }
        try {
            P = new char[taille];
            longueur = taille;
            estCree = true;
            cout << "Allocation de " << taille << " octets réussie" << endl;
            return true;
        }
        catch (const bad_alloc& e) {
            cout << "Erreur d'allocation mémoire: " << e.what() << endl;
            return false;
        }
    }
    void Remplit() {
        if (!estCree || P == nullptr) {
            cout << "Erreur: Le fichier n'est pas créé!" << endl;
            return;
        }
        // Remplissage avec des caractères aléatoires entre 'A' et 'Z'
        srand(time(nullptr));
        for (size_t i = 0; i < longueur; i++) {
            P[i] = 'A' + (rand() % 26);
        }
        cout << "Remplissage du fichier terminé" << endl;
    }
    
    void Affiche() const {
        if (!estCree || P == nullptr) {
            cout << "Erreur: Le fichier n'est pas créé!" << endl;
            return;
        }

        cout << "Contenu du fichier (" << longueur << " octets):" << endl;

        // Affichage en format hexadécimal et caractères
        for (size_t i = 0; i < longueur; i++) {
            // Affichage de l'adresse au début de chaque ligne
            if (i % 16 == 0) {
                if (i > 0) cout << endl;
                cout << hex << uppercase << setw(8) << setfill('0')
                     << reinterpret_cast<size_t>(P + i) << ": ";
            }

            // Affichage en hexadécimal
            cout << hex << uppercase << setw(2) << setfill('0')
                 << static_cast<int>(static_cast<unsigned char>(P[i])) << " ";

            // Affichage des caractères à la fin de chaque ligne
            if (i % 16 == 15 || i == longueur - 1) {
                // Compléter avec des espaces si nécessaire
                if (i % 16 != 15) {
                    for (size_t j = 0; j < 15 - (i % 16); j++) {
                        cout << "   ";
                    }
                }
                cout << " | ";
                // Affichage des caractères
                for (size_t j = i - (i % 16); j <= i; j++) {
                    char c = P[j];
                    cout << (isprint(c) ? c : '.');
                }
            }
        }
        cout << dec << endl; // Retour au format décimal
    }
    
    size_t getLongueur() const {
        return longueur;
    }

    // Méthode pour vérifier si le fichier est créé
    bool estValide() const {
        return estCree && P != nullptr;
    }
};

int main() {
    cout << "=== Test de la classe Fichier ===" << endl << endl;
    
    Fichier* fichier = new Fichier();
    
    cout << "Test de création du fichier:" << endl;
    if (!fichier->Creation(64)) {
        delete fichier;
        return 1;
    }
    
    cout << "\nTest de remplissage du fichier:" << endl;
    fichier->Remplit();

    cout << "\nTest d'affichage du fichier:" << endl;
    fichier->Affiche();
    
    cout << "\nTest de création multiple:" << endl;
    fichier->Creation(32);
    
    cout << "\nDestruction du fichier:" << endl;
    delete fichier;
    
    cout << "\nTest avec un nouveau fichier:" << endl;
    Fichier* fichier2 = new Fichier();
    fichier2->Creation(32);
    fichier2->Remplit();
    fichier2->Affiche();
    delete fichier2;

    return 0;
}
