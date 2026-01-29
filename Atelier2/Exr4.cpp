#include <iostream>
#include <limits>

using namespace std;

int main() {
    int taille;

    // Lire la taille du tableau
    cout << "Donnez la taille du tableau d'entiers : ";
    if (!(cin >> taille) || taille <= 0) {
        cerr << "Erreur : la taille doit être un entier positif." << endl;
        return 1;
    }

    // 1. Allouer dynamiquement le premier tableau
    int* tab = new int[taille];

    // Remplir le tableau avec des entiers lus en données
    cout << "Entrez " << taille << " nombres entiers :" << endl;
    for (int i = 0; i < taille; ++i) {
        cout << " " << i + 1 << " : ";
        while (!(cin >> tab[i])) {
            cout << "Erreur. Entrez un entier : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // 2. le nouveau tableau pour recevoir les carrés
    int* tabCarres = new int[taille];
    for (int i = 0; i < taille; ++i) {
        tabCarres[i] = tab[i] * tab[i];
    }

    // 3. Supprimer le premier tableau
    delete[] tab;
    tab = nullptr;

    // Afficher les valeurs du second tableau
    cout << "Tableau des carres :" << endl;
    for (int i = 0; i < taille; ++i) {
        cout << "Carre " << i + 1 << " : " << tabCarres[i] << endl;
    }

    // tout est supprimé
    delete[] tabCarres;
    tabCarres = nullptr;

    return 0;
}
