#include <iostream>
#include <string>
#include <iomanip>

class DateParser {
private:
    std::string dateStr;
    int jour;
    int mois;
    int annee;
    int heure;
    int minute;

    bool validerFormat() {
        // Vérifier la longueur
        if (dateStr.length() != 12) return false;
        // Vérifier que tous les caractères sont des chiffres
        for (char c : dateStr) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    void extraireChamps() {
        jour = std::stoi(dateStr.substr(0, 2));
        mois = std::stoi(dateStr.substr(2, 2));
        annee = std::stoi(dateStr.substr(4, 4));
        heure = std::stoi(dateStr.substr(8, 2));
        minute = std::stoi(dateStr.substr(10, 2));
    }

    bool validerValeurs() {
        if (jour < 1 || jour > 31) return false;
        if (mois < 1 || mois > 12) return false;
        if (annee < 1) return false;
        if (heure < 0 || heure > 23) return false;
        if (minute < 0 || minute > 59) return false;
        return true;
    }

public:
    bool parseDate(const std::string& input) {
        dateStr = input;

        // Vérifier le format
        if (!validerFormat()) {
            std::cout << "Format invalide. Utilisez JJMMAAAAHHMM" << std::endl;
            return false;
        }

        // Extraire les champs
        extraireChamps();

        // Valider les valeurs
        if (!validerValeurs()) {
            std::cout << "Valeurs de date/heure invalides" << std::endl;
            return false;
        }

        return true;
    }

    void afficherDate() {
        std::cout << "Date : " << std::setfill('0') << std::setw(2) << jour
                  << "/" << std::setfill('0') << std::setw(2) << mois
                  << "/" << annee << std::endl;
        std::cout << "Heure : " << std::setfill('0') << std::setw(2) << heure
                  << ":" << std::setfill('0') << std::setw(2) << minute << std::endl;
    }

    // Getters pour accéder aux champs individuels
    int getJour() const { return jour; }
    int getMois() const { return mois; }
    int getAnnee() const { return annee; }
    int getHeure() const { return heure; }
    int getMinute() const { return minute; }
};

int main() {
    DateParser parser;
    std::string input;

    std::cout << "Entrez une date (JJMMAAAAHHMM) : ";
    std::cin >> input;

    if (parser.parseDate(input)) {
        parser.afficherDate();
    }

    return 0;
}
