#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ============================
// Classe Telechargeable
// ============================
class Telechargeable {
public:
    virtual ~Telechargeable() {}

    virtual void telecharger() const {
        cout << "Téléchargement générique d'une ressource..." << endl;
    }

    virtual void afficherMessage() const {
        cout << "Cette ressource peut être téléchargée." << endl;
    }
};

// ============================
// Classe Ressource (classe de base)
// ============================
class Ressource {
protected:
    int id;
    string titre;
    string auteur;
    int annee;

public:
    Ressource(int _id, const string& _titre, const string& _auteur, int _annee)
        : id(_id), titre(_titre), auteur(_auteur), annee(_annee) {}

    virtual ~Ressource() {}

    virtual void afficherInfos() const {
        cout << "ID : " << id << endl;
        cout << "Titre : " << titre << endl;
        cout << "Auteur : " << auteur << endl;
        cout << "Annee : " << annee << endl;
    }

    virtual void telecharger() const {
        cout << "Téléchargement de la ressource générique : " << titre << endl;
    }

    // Accesseurs
    string getTitre() const { return titre; }
    string getAuteur() const { return auteur; }
    int getAnnee() const { return annee; }

    // Surcharge opérateur ==
    bool operator==(const Ressource& autre) const {
        return this->id == autre.id;
    }
};

// ============================
// Classe Livre
// ============================
class Livre : public Ressource, public Telechargeable {
private:
    int nbPages;

public:
    Livre(int _id, const string& _titre, const string& _auteur, int _annee, int _nbPages)
        : Ressource(_id, _titre, _auteur, _annee), nbPages(_nbPages) {}

    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << "Nombre de pages : " << nbPages << endl;
        afficherMessage();
    }

    void telecharger() const override {
        cout << "Téléchargement du livre \"" << titre << "\" en format PDF..." << endl;
    }
};

// ============================
// Classe Magazine
// ============================
class Magazine : public Ressource, public Telechargeable {
private:
    int numero;

public:
    Magazine(int _id, const string& _titre, const string& _auteur, int _annee, int _numero)
        : Ressource(_id, _titre, _auteur, _annee), numero(_numero) {}

    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << "Numéro du magazine : " << numero << endl;
        afficherMessage();
    }

    void telecharger() const override {
        cout << "Téléchargement du magazine \"" << titre << "\" (numéro " << numero << ")..." << endl;
    }
};

// ============================
// Classe Video
// ============================
class Video : public Ressource, public Telechargeable {
private:
    int duree; // en minutes

public:
    Video(int _id, const string& _titre, const string& _auteur, int _annee, int _duree)
        : Ressource(_id, _titre, _auteur, _annee), duree(_duree) {}

    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << "Durée de la vidéo : " << duree << " minutes" << endl;
        afficherMessage();
    }

    void telecharger() const override {
        cout << "Téléchargement de la vidéo \"" << titre << "\" en cours..." << endl;
    }
};

// ============================
// Classe Mediatheque
// ============================
class Mediatheque {
private:
    vector<Ressource*> ressources;

public:
    ~Mediatheque() {
        for (auto r : ressources)
            delete r;
    }

    void ajouterRessource(Ressource* r) {
        ressources.push_back(r);
    }

    void afficherToutes() const {
        cout << "===== Liste des ressources =====" << endl;
        for (auto r : ressources) {
            r->afficherInfos();
            cout << "--------------------------" << endl;
        }
    }

    // Rechercher par titre
    void rechercher(const string& titre) const {
        cout << "Recherche par titre : " << titre << endl;
        for (auto r : ressources)
            if (r->getTitre() == titre)
                r->afficherInfos();
    }

    // Rechercher par année
    void rechercher(int annee) const {
        cout << "Recherche par année : " << annee << endl;
        for (auto r : ressources)
            if (r->getAnnee() == annee)
                r->afficherInfos();
    }

    // Rechercher par auteur + année
    void rechercher(const string& auteur, int annee) const {
        cout << "Recherche par auteur : " << auteur << " et année : " << annee << endl;
        for (auto r : ressources)
            if (r->getAuteur() == auteur && r->getAnnee() == annee)
                r->afficherInfos();
    }
};

// ============================
// MAIN
// ============================
int main() {
    // Création d'objets
    Livre l1(1, "Les Misérables", "Victor Hugo", 1862, 1200);
    Livre l2(2, "Notre-Dame de Paris", "Victor Hugo", 1831, 940);
    Magazine m1(3, "Science & Vie", "Rédaction", 2024, 987);
    Video v1(4, "Inception", "Christopher Nolan", 2010, 148);

    cout << "===== Test des méthodes afficherInfos() =====" << endl;
    l1.afficherInfos();
    cout << endl;
    m1.afficherInfos();
    cout << endl;
    v1.afficherInfos();

    cout << "\n===== Test des méthodes telecharger() =====" << endl;
    l1.Livre::telecharger();
    m1.Magazine::telecharger();
    v1.Video::telecharger();

    cout << "\n===== Test de la comparaison (==) =====" << endl;
    if (l1 == l2)
        cout << "Les ressources l1 et l2 ont le même identifiant." << endl;
    else
        cout << "Les ressources l1 et l2 sont différentes (IDs distincts)." << endl;

    Livre l3(1, "Autre Livre", "Auteur X", 2020, 300);
    if (l1 == l3)
        cout << "Les ressources l1 et l3 ont le même identifiant." << endl;
    else
        cout << "Les ressources l1 et l3 sont différentes." << endl;

    cout << "\n===== Test de la classe Mediatheque =====" << endl;
    Mediatheque med;
    med.ajouterRessource(new Livre(l1));
    med.ajouterRessource(new Magazine(m1));
    med.ajouterRessource(new Video(v1));

    med.afficherToutes();
    cout << endl;

    med.rechercher("Inception");
    cout << endl;
    med.rechercher(2024);
    cout << endl;
    med.rechercher("Victor Hugo", 1862);

    return 0;
}