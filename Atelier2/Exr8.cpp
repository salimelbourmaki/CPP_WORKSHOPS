#include <iostream>
#include <string>
using namespace std;

class Voiture {
private:
    string marque;
    string modele;
    int annee;
    float kilometrage;
    float vitesse;

public:
    // a. Constructeur par défaut
    Voiture() {
        marque = "Inconnu";
        modele = "Inconnu";
        annee = 0;
        kilometrage = 0.0f;
        vitesse = 0.0f;
    }
    // b. Constructeur avec paramètres
    Voiture(string m, string mod, int a, float km, float v) {
        marque = m;
        modele = mod;
        annee = a;
        kilometrage = km;
        vitesse = v;
    }
    // c. Méthode accelerer
    void accelerer(float valeur) {
        vitesse += valeur;
    }

    // d. Méthode freiner
    void freiner(float valeur) {
        vitesse -= valeur;
        if (vitesse < 0)
            vitesse = 0;
    }
    // e. Méthode afficherInfo
    void afficherInfo() const {
        cout << "Marque : " << marque << endl;
        cout << "Modele : " << modele << endl;
        cout << "Annee : " << annee << endl;
        cout << "Kilometrage : " << kilometrage << " km" << endl;
        cout << "Vitesse actuelle : " << vitesse << " km/h" << endl;
    }
    // f. Méthode avancer
    void avancer(float distance) {
        kilometrage += distance;
    }
    // g. Destructeur
    ~Voiture() {
        cout << "La voiture " << marque << " " << modele << " est detruite" << endl;
    }
};
int main() {
    Voiture v1("MERCEDES", "AMG", 2025, 500, 260);
    v1.afficherInfo();
    cout << "\nAcceleration:" << endl;
    v1.accelerer(20);
    v1.afficherInfo();
    cout << "\nFreinage:" << endl;
    v1.freiner(100);
    v1.afficherInfo();
    cout << "\nAvancer de 120 km:" << endl;
    v1.avancer(120);
    v1.afficherInfo();

    return 0;
}
