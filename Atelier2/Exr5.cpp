#include <iostream>
#include <limits>
using namespace std;

int main() {
    int a; //1. declaation de a
    cout << "Entrez un entier pour a : ";
    cin>>a;

    // 2. declaration d'une référence vers cet entier ref_a
    int& ref_a = a;

    // 3. declaration d'un pointeur vers cet entier p_a
    int* p_a = &a;

    // 4. Affichage des variables, de leurs adresses et de la valeur pointée
    cout << "Variable a : " << a << ", Adresse : " << &a << endl;
    cout << "Reference ref_a : " << ref_a << ", Adresse : " << &ref_a << endl;
    cout << "Pointeur p_a : " << p_a << ", Valeur pointee : " << *p_a << ", Adresse du pointeur : " << &p_a << endl;

    return 0;
}
