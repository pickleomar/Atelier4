#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string nom;
    int age;
public:
    virtual void set_value(string n, int a) {
        nom = n;
        age = a;
    }
};

class Zebra : public Animal {
private:
    string origine;
public:
    void set_value(string n, int a, string o = "Afrique") {  //default origine
        Animal::set_value(n, a);
        origine = o;
    }
    void Affiche_Info() {
        cout << "Zebra" << endl;
        cout << "Nom: " << nom << endl;
        cout << "Age: " << age << " ans" << endl;
        cout << "Lieu d'origine: " << origine << endl <<endl;
    }
};

class Dolphin : public Animal {
private:
    string origine;
public:
    void set_value(string n, int a, string o = "Ocean Atlantique") { //default origine
        Animal::set_value(n, a);
        origine = o;
    }
    void Affiche_Info() {
        cout << "Dauphin" << endl;
        cout << "Nom: " << nom << endl;
        cout << "Age: " << age << " ans" << endl;
        cout << "Lieu d'origine: " << origine<< endl <<endl;
    }
};

int main() {
    Zebra zebra;
    Dolphin dolphin;
    zebra.set_value("Ziggy ", 4); //Possibilité d'ajouter un paramètre origine
    dolphin.set_value("Splash", 7); //Possibilité d'ajouter un paramètre origine
    zebra.Affiche_Info();
    dolphin.Affiche_Info();
    return 0;
}
