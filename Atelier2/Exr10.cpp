#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Classe représentant un nombre complexe.
 * Un nombre complexe est de la forme a + bi, où 'a' est la partie réelle et 'b' est la partie imaginaire.
 */
class NombreComplexe {
private:
    float reel;
    float imaginaire;

public:
    // Constructeur
    NombreComplexe(float r = 0.0f, float i = 0.0f) : reel(r), imaginaire(i) {}

    // Accesseurs
    float getReel() const { return reel; }
    float getImaginaire() const { return imaginaire; }

    // Méthode d'affichage
    void afficher() const {
        cout << "(" << reel << " + " << imaginaire << "i)";
    }

    // 1. Égalité (vérification)
    bool estEgal(const NombreComplexe& autre) const {
        // Pour les floats, on utilise généralement une petite tolérance (epsilon)
        const float epsilon = 1e-6; 
        return (abs(reel - autre.reel) < epsilon) && (abs(imaginaire - autre.imaginaire) < epsilon);
    }

    // 2. Addition (retourne un nouveau NombreComplexe)
    NombreComplexe additionner(const NombreComplexe& autre) const {
        return NombreComplexe(reel + autre.reel, imaginaire + autre.imaginaire);
    }

    // 3. Soustraction (retourne un nouveau NombreComplexe)
    NombreComplexe soustraire(const NombreComplexe& autre) const {
        return NombreComplexe(reel - autre.reel, imaginaire - autre.imaginaire);
    }

    // 4. Multiplication (retourne un nouveau NombreComplexe)
    // Formule : (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    NombreComplexe multiplier(const NombreComplexe& autre) const {
        float nouveauReel = (reel * autre.reel) - (imaginaire * autre.imaginaire);
        float nouvelImaginaire = (reel * autre.imaginaire) + (imaginaire * autre.reel);
        return NombreComplexe(nouveauReel, nouvelImaginaire);
    }

    // 5. Division (retourne un nouveau NombreComplexe)
    // Formule : (a + bi) / (c + di) = [(ac + bd) / (c² + d²)] + [(bc - ad) / (c² + d²)]i
    NombreComplexe diviser(const NombreComplexe& autre) const {
        float denominateur = (autre.reel * autre.reel) + (autre.imaginaire * autre.imaginaire);

        // Vérification de la division par zéro
        if (denominateur == 0.0f) {
            cerr << "Erreur: Division par zero (le denominateur est nul)!" << endl;
            // Retourne un complexe par défaut (0, 0) pour gérer l'erreur
            return NombreComplexe(NAN, NAN); // NAN (Not a Number) pour marquer une erreur
        }

        float nouveauReel = ((reel * autre.reel) + (imaginaire * autre.imaginaire)) / denominateur;
        float nouvelImaginaire = ((imaginaire * autre.reel) - (reel * autre.imaginaire)) / denominateur;

        return NombreComplexe(nouveauReel, nouvelImaginaire);
    }
};

/**
 * @brief Fonction pour lire un nombre complexe à partir de l'entrée utilisateur.
 */
NombreComplexe lireComplexe(const string& nom) {
    float r, i;
    cout << "\nSaisir la partie reelle de " << nom << " : ";
    cin >> r;
    cout << "Saisir la partie imaginaire de " << nom << " : ";
    cin >> i;
    return NombreComplexe(r, i);
}

/**
 * @brief Fonction d'affichage du menu.
 */
void afficherMenu() {
    cout << "\nMENU OPERATIONS " << endl;
 
    cout << "1. Egalite (Verifier si C1 = C2)" << endl;
    cout << "2. Addition (C1 + C2)" << endl;
    cout << "3. Soustraction (C1 - C2)" << endl;
    cout << "4. Multiplication (C1 * C2)" << endl;
    cout << "5. Division (C1 / C2)" << endl;
    cout << "0. Quitter" << endl;
    cout << "Votre choix : ";
}

/**
 * @brief Fonction principale
 */
int main() {
    int choix;
    NombreComplexe c1, c2;

    cout << "Saisir des Nombres Complexes:" << endl;
    c1 = lireComplexe("C1");
    c2 = lireComplexe("C2");

    do {
        afficherMenu();
        if (!(cin >> choix)) {
            // Gestion de l'erreur d'entrée (e.g., l'utilisateur entre du texte)
            cin.clear();
            cin.ignore(10000, '\n');
            choix = -1;
            continue;
        }

        NombreComplexe resultat;
        cout << "\nResultat de l'operation : ";

        switch (choix) {
            case 1: // Egalité
                cout << "C1 "; c1.afficher();
                cout << " et C2 "; c2.afficher();
                if (c1.estEgal(c2)) {
                    cout << " sont egaux." << endl;
                } else {
                    cout << " ne sont pas egaux." << endl;
                }
                break;

            case 2: // Addition
                resultat = c1.additionner(c2);
                cout << "C1 + C2 = ";
                resultat.afficher();
                cout << " (Partie Reelle : " << resultat.getReel() << ", Partie Imaginaire : " << resultat.getImaginaire() << "i)" << endl;
                break;

            case 3: // Soustraction
                resultat = c1.soustraire(c2);
                cout << "C1 - C2 = ";
                resultat.afficher();
                cout << " (Partie Reelle : " << resultat.getReel() << ", Partie Imaginaire : " << resultat.getImaginaire() << "i)" << endl;
                break;

            case 4: // Multiplication
                resultat = c1.multiplier(c2);
                cout << "C1 * C2 = ";
                resultat.afficher();
                cout << " (Partie Reelle : " << resultat.getReel() << ", Partie Imaginaire : " << resultat.getImaginaire() << "i)" << endl;
                break;

            case 5: // Division
                resultat = c1.diviser(c2);
                if (!isnan(resultat.getReel())) { // Vérifie si la division n'a pas retourné d'erreur (NAN)
                    cout << "C1 / C2 = ";
                    resultat.afficher();
                    cout << " (Partie Reelle : " << resultat.getReel() << ", Partie Imaginaire : " << resultat.getImaginaire() << "i)" << endl;
                }
                break;

            case 0:
                cout << "Fin" << endl;
                break;

            default:
                cout << "Choix invalide. Veuillez ressayer." << endl;
                break;
        }
    } while (choix != 0);

    return 0;
}