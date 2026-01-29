#include <iostream>
using namespace std;

// Structure représentant un élément de la liste
struct Element {
    int valeur;          // donnée stockée
    Element* suivant;    // pointeur vers l'élément suivant
};

// Classe représentant la liste simplement chaînée
class Liste {
private:
    Element* tete;  // pointeur sur le premier élément

public:
    // Constructeur
    Liste() {
        tete = nullptr;
        cout << "Liste initialisée (vide)." << endl;
    }

    // Destructeur
    ~Liste() {
        // Libération de toute la mémoire allouée
        while (tete != nullptr) {
            Element* tmp = tete;
            tete = tete->suivant;
            delete tmp;
        }
        cout << "Destructeur : mémoire libérée, liste détruite." << endl;
    }

    // Méthode pour ajouter un élément au début de la liste
    void ajouter_debut(int valeur) {
        Element* nouveau = new Element; // alloue un nouveau nœud
        nouveau->valeur = valeur;
        nouveau->suivant = tete;        // le nouveau pointe sur l'ancien premier
        tete = nouveau;                 // il devient la nouvelle tête
        cout << "Ajouté au début : " << valeur << endl;
    }

    // Méthode pour supprimer l'élément au début
    void supprimer_debut() {
        if (tete == nullptr) {
            cout << "Liste vide, rien à supprimer." << endl;
            return;
        }

        Element* tmp = tete;
        tete = tete->suivant;
        cout << "Supprimé du début : " << tmp->valeur << endl;
        delete tmp; // libère la mémoire de l’ancien premier
    }

    // Méthode pour afficher la liste entière
    void afficher() {
        if (tete == nullptr) {
            cout << "Liste vide." << endl;
            return;
        }

        cout << "Contenu de la liste : ";
        Element* courant = tete;
        while (courant != nullptr) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }
        cout << endl;
    }
};

// Programme principal de test
int main() {
    Liste maListe;

    maListe.ajouter_debut(10);
    maListe.ajouter_debut(20);
    maListe.ajouter_debut(30);

    maListe.afficher();

    maListe.supprimer_debut();
    maListe.afficher();

    maListe.supprimer_debut();
    maListe.supprimer_debut();
    maListe.supprimer_debut(); // test sur liste vide

    return 0;
}
