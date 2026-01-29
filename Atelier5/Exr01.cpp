#include <iostream>
using namespace std;

class Pile {
private:
    int *tab;      // tableau dynamique pour stocker les éléments
    int tailleMax; // taille maximale de la pile
    int sommet;    // indice du dernier élément empilé (sommet de la pile)

public:
    // Constructeur
    Pile(int taille = 10) {
        tailleMax = taille;
        tab = new int[tailleMax];
        sommet = -1; // pile vide
    }

    // Destructeur
    ~Pile() {
        delete[] tab;
    }

    // Empiler un élément
    void push(int valeur) {
        if (sommet == tailleMax - 1) {
            cout << "Erreur : pile pleine, impossible d'empiler " << valeur << endl;
        } else {
            tab[++sommet] = valeur;
            cout << "Empilé : " << valeur << endl;
        }
    }

    // Dépiler un élément
    int pop() {
        if (sommet == -1) {
            cout << "Erreur : pile vide, rien à dépiler." << endl;
            return -1;
        } else {
            cout << "Dépilé : " << tab[sommet] << endl;
            return tab[sommet--];
        }
    }

    // Afficher la pile
    void afficher() {
        if (sommet == -1) {
            cout << "Pile vide." << endl;
            return;
        }
        cout << "Contenu de la pile : ";
        for (int i = 0; i <= sommet; i++) {
            cout << tab[i] << " ";
        }
        cout << endl;
    }
};

// Programme principal de test
int main() {
    // Création de deux piles
    Pile p1(5);
    Pile p2(3);

    cout << "=== Test de la pile p1 ===" << endl;
    p1.push(10);
    p1.push(20);
    p1.push(30);
    p1.afficher();

    p1.pop();
    p1.afficher();

    cout << "\n=== Test de la pile p2 ===" << endl;
    p2.push(1);
    p2.push(2);
    p2.push(3);
    p2.push(4); // test dépassement
    p2.afficher();

    p2.pop();
    p2.pop();
    p2.afficher();

    return 0;
}
