#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double img;
public:
    Complex(double r = 0, double i = 0) : real(r), img(i) {}

    void afficher() const {
        cout << real;
        if (img >= 0) cout << " + ";
        cout << img << "i" << endl;
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, img + other.img);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, img - other.img);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
                real * other.real - img * other.img,
                real * other.img + img * other.real
        );
    }
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.img * other.img;
        return Complex(
                (real * other.real + img * other.img) / denominator,
                (img * other.real - real * other.img) / denominator
        );
    }
    bool operator==(const Complex& other) const {
        return (real == other.real && img == other.img);
    }
    friend istream& operator>>(istream& in, Complex& c);
};

istream& operator>>(istream& in, Complex& c) {
    cout << "Entez la partie reel: ";
    in >> c.real;
    cout << "Entrez la partie imaginaire: ";
    in >> c.img;
    return in;
}

int main() {
    Complex c1, c2, result;
    int choix;

    cout << "Pour le premier nombre complexe:\n";
    cin >> c1;
    cout << "Pour le second nombre complexe:\n";
    cin >> c2;

    do {
        cout << "\nLes Operations Complex:\n";
        cout << "1. Addition\n";
        cout << "2. Soustraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Verifier l'egalite\n";
        cout << "6. Sortir\n";
        cout << "Enterez votre choix: ";
        cin >> choix;
        switch(choix) {
            case 1:
                result = c1 + c2;
                cout << "Somme: ";
                result.afficher();
                break;
            case 2:
                result = c1 - c2;
                cout << "Difference: ";
                result.afficher();
                break;
            case 3:
                result = c1 * c2;
                cout << "Produit: ";
                result.afficher();
                break;
            case 4:
                result = c1 / c2;
                cout << "Quotient: ";
                result.afficher();
                break;
            case 5:
                if (c1 == c2)
                    cout << "Les nombres Complexes sont egaux\n";
                else
                    cout << "Les nombres Complexes ne sont pas egaux\n";
                break;
            case 6:
                cout << "Sortir...\n";
                break;
            default:
                cout << "Choix Invalide!\n";
        }
    } while (choix != 6);
    return 0;
}