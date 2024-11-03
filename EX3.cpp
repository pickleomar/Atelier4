#include <iostream>
#include <string>
using namespace std;

class Personne {
private:
    string nom;
    string prenom;
    string DateNaissance;
public:
    Personne(string n, string p, string d) : nom(n), prenom(p), DateNaissance(d) {}

    virtual void Afficher() const {
        cout << "Nom: " << nom << endl;
        cout << "Prenom: " << prenom << endl;
        cout << "Date de naissance: " << DateNaissance << endl;
    }
    virtual ~Personne() {}
};

class Employe : public Personne {
private:
    double salaire;

public:
    Employe(string n, string p, string d, double s)
            : Personne(n, p, d), salaire(s) {}

    double getSalaire() const { return salaire; }
    void setSalaire(double s) { salaire = s; }

    void Afficher() const override {
        Personne::Afficher();
        cout << "Salaire: " << salaire << " €" << endl;
    }
};

class Chef : public Employe {
private:
    string service;
public:
    Chef(string n, string p, string d, double s, string serv)
            : Employe(n, p, d, s), service(serv) {}

    string getService() const { return service; }
    void setService(string s) { service = s; }

    void Afficher() const override {
        Employe::Afficher();
        cout << "Service: " << service << endl;
    }
};

class Directeur : public Chef {
private:
    string societe;

public:
    // Constructeur
    Directeur(string n, string p, string d, double s, string serv, string soc)
            : Chef(n, p, d, s, serv), societe(soc) {}

    string getSociete() const { return societe; }
    void setSociete(string s) { societe = s; }

    void Afficher() const override {
        Chef::Afficher();
        cout << "Société: " << societe << endl;
    }
};

int main() {
    // Création des objets
    cout << "=== Test de la hiérarchie des classes ===" << endl << endl;
    cout << "--- Employé ---" << endl;
    Employe emp("Said", "taghmaoui", "19/07/1973", 35000);
    emp.Afficher();
    cout << endl;
    cout << "--- Chef ---" << endl;
    Chef chef("Gaspar", "Noe", "27/12/1963", 50000, "Ressources Humaines");
    chef.Afficher();
    cout << endl;
    cout << "--- Directeur ---" << endl;
    Directeur dir("Nolan", "Christopher", "30/07/1970", 80000, "Direction Générale", "ThrillCorp SA");
    dir.Afficher();
    return 0;
}
