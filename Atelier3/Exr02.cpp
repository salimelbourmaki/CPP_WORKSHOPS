#include <iostream>
#include <cstring> // pour memset si besoin
using namespace std;

class Fichier {
private:
    char* P;       // pointeur sur la zone mémoire
    long longueur; // taille du "fichier" en octets

public:
    // Constructeur
    Fichier() {
        P = nullptr;
        longueur = 0;
        cout << "Constructeur : Fichier créé (vide)" << endl;
    }

    // Méthode pour allouer un espace mémoire
    void Creation(long n) {
        longueur = n;
        P = new char[longueur];  // allocation dynamique
        cout << "Espace de " << longueur << " octets alloué." << endl;
    }

    // Méthode pour remplir arbitrairement la mémoire
    void Remplit() {
        if (P == nullptr) {
            cout << "Erreur : aucune zone mémoire allouée !" << endl;
            return;
        }

        for (long i = 0; i < longueur; i++) {
            P[i] = 'A' + (i % 26); // Remplit avec des lettres A-Z
        }

        cout << "Zone mémoire remplie arbitrairement." << endl;
    }

    // Méthode pour afficher le contenu mémoire
    void Affiche() {
        if (P == nullptr) {
            cout << "Erreur : aucune zone mémoire à afficher !" << endl;
            return;
        }

        cout << "Contenu du fichier en mémoire : ";
        for (long i = 0; i < longueur; i++) {
            cout << P[i];
        }
        cout << endl;
    }

    // Destructeur
    ~Fichier() {
        delete[] P; // libère la mémoire
        cout << "Destructeur : mémoire libérée." << endl;
    }
};

// Programme principal de test
int main() {
    cout << "=== Début du programme ===" << endl;

    // Création dynamique d’un objet Fichier
    Fichier* f = new Fichier();

    // Appel des méthodes
    f->Creation(30);   // alloue 30 octets
    f->Remplit();      // remplit la zone mémoire
    f->Affiche();      // affiche le contenu

    // Destruction de l’objet
    delete f;

    cout << "=== Fin du programme ===" << endl;
    return 0;
}