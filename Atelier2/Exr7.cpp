#include <iostream>
using namespace std;

void permut(string& chaine, int debut, int fin) {
    if (debut == fin) {
        cout << chaine << endl; 
    }
    else {
        int i;
        for (i = debut; i <= fin; i++) {
            char temp = chaine[debut]; // pour l'echange des caractrzres 
            chaine[debut] = chaine[i];
            chaine[i] = temp;

            permut(chaine, debut + 1, fin);

            temp = chaine[debut];
            chaine[debut] = chaine[i];
            chaine[i] = temp;
        }
    }
}

int main() {
    string s;
    cout << "Veuillez saisir une chaine : \n";
    cin >> s;

    cout << "Les permutations possibles :" << endl;
    permut(s, 0, s.length() - 1);

    return 0;
}
