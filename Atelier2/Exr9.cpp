#include <iostream>
#include <cmath> // Pour la fonction std::sqrt

using namespace std;

class vecteur3d {
private:
    float x;
    float y;
    float z;

public:
    // 1. Constructeur avec valeurs par défaut (0)
    vecteur3d(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) : x(_x), y(_y), z(_z) {}

    // 2. Fonction d’affichage des 3 composantes
    void affiche() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    // 3. Fonction permettant d’obtenir la somme de 2 vecteurs
    // L'autre vecteur est passé par référence constante pour l'efficacité.
    vecteur3d somme(const vecteur3d& autre) const {
        return vecteur3d(x + autre.x, y + autre.y, z + autre.z);
    }

    // 4. Fonction permettant d’obtenir le produit scalaire de 2 vecteurs
    float produitScalaire(const vecteur3d& autre) const {
        return (x * autre.x) + (y * autre.y) + (z * autre.z);
    }

    // 5. Fonction coincide permettant de savoir si 2 vecteurs ont mêmes composantes
    bool coincide(const vecteur3d& autre) const {
        // Utiliser une petite tolérance (epsilon) pour la comparaison des floats est souvent préférable,
        // mais pour simplifier, nous allons utiliser l'égalité directe.
        return (x == autre.x) && (y == autre.y) && (z == autre.z);
    }

    // 6. Fonction qui renvoie la norme du vecteur
    float norme() const {
        return std::sqrt(produitScalaire(*this)); // Le produit scalaire d'un vecteur avec lui-même est sa norme au carré.
    }

    // 7. Fonction norme_max
    // Renvoie le vecteur avec la plus grande norme.

    // a. Résultat renvoyé par valeur
    vecteur3d normeMax_valeur(const vecteur3d& autre) const {
        if (this->norme() >= autre.norme()) {
            return *this;
        } else {
            return autre;
        }
    }

    // b. Résultat renvoyé par adresse, l’argument étant également transmis par adresse
    static vecteur3d* normeMax_adresse(const vecteur3d* v1, const vecteur3d* v2) {
        if (!v1 || !v2) return nullptr; // Vérification de sécurité

        if (v1->norme() >= v2->norme()) {
            // Note: On ne peut pas renvoyer 'this' ou 'autre' car ce n'est pas une fonction membre
            // sur une instance particulière dans ce contexte. Si elle était membre, ce serait:
            // return (this->norme() >= autre->norme()) ? this : autre;
            // En tant que fonction static, elle doit retourner l'une des adresses reçues.
            return const_cast<vecteur3d*>(v1); // const_cast est nécessaire pour enlever le const des pointeurs d'entrée.
        } else {
            return const_cast<vecteur3d*>(v2);
        }
    }

    // c. Résultat renvoyé par référence, l’argument étant également transmis par référence
    const vecteur3d& normeMax_reference(const vecteur3d& autre) const {
        if (this->norme() >= autre.norme()) {
            return *this;
        } else {
            return autre;
        }
    }
};

// Fonction de test (main) pour démontrer l'utilisation de la classe
int main() {
    // Création des vecteurs
    vecteur3d v1(1.0f, 2.0f, 3.0f);
    vecteur3d v2(3.0f, 2.0f, 1.0f);
    vecteur3d v3(1.0f, 2.0f, 3.0f);
    vecteur3d v4(4.0f, -1.0f, 5.0f);

    cout << "Vecteur v1: "; v1.affiche(); cout << endl;
    cout << "Vecteur v2: "; v2.affiche(); cout << endl;
    cout << "Vecteur v3: "; v3.affiche(); cout << endl;
    cout << "Vecteur v4: "; v4.affiche(); cout << endl;

    // 3. Somme
    vecteur3d vSomme = v1.somme(v2);
    cout << "\nSomme (v1 + v2): "; vSomme.affiche(); cout << endl;

    // 4. Produit Scalaire
    float ps = v1.produitScalaire(v2);
    cout << "Produit Scalaire (v1 . v2): " << ps << endl;

    // 5. Coincidence
    cout << "v1 coincide avec v3 ? " << (v1.coincide(v3) ? "Oui" : "Non") << endl;
    cout << "v1 coincide avec v2 ? " << (v1.coincide(v2) ? "Oui" : "Non") << endl;

    // 6. Norme
    cout << "Norme de v1: " << v1.norme() << endl; // sqrt(1^2 + 2^2 + 3^2) = sqrt(14) ≈ 3.74
    cout << "Norme de v4: " << v4.norme() << endl; // sqrt(4^2 + (-1)^2 + 5^2) = sqrt(16 + 1 + 25) = sqrt(42) ≈ 6.48

    // 7. Norme Max

    // a. Renvoi par valeur
    vecteur3d vMax_val = v1.normeMax_valeur(v4);
    cout << "\nNorme Max (v1 vs v4) - Valeur: "; vMax_val.affiche(); cout << " (Norme: " << vMax_val.norme() << ")" << endl;

    // b. Renvoi par adresse
    vecteur3d* vMax_addr = vecteur3d::normeMax_adresse(&v1, &v4);
    if (vMax_addr) {
        cout << "Norme Max (v1 vs v4) - Adresse: "; vMax_addr->affiche(); cout << " (Norme: " << vMax_addr->norme() << ")" << endl;
    }

    // c. Renvoi par référence
    const vecteur3d& vMax_ref = v1.normeMax_reference(v4);
    cout << "Norme Max (v1 vs v4) - Référence: "; vMax_ref.affiche(); cout << " (Norme: " << vMax_ref.norme() << ")" << endl;

    return 0;
}