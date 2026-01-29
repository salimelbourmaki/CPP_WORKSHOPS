#include <iostream>
using namespace std;

void incrmt_adr(int* x) {
    (*x)++;
}

void permut_adr(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void incrmt_ref(int& x) {  //methode en c
    x++;
}

void permut_ref(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    int a = 5, b = 10;
    cout << "en transmettant l’adresse des variables concernées en C :" << endl;
    cout << "Avant : a = " << a << endl;
    incrmt_adr(&a);
    cout << "Apres incrementer_adresse : a = " << a << endl;

    cout << "Avant permutation : a = " << a << ", b = " << b << endl;
    permut_adr(&a, &b);
    cout << "Apres permuter_adresse  : a = " << a << ", b = " << b << endl;

    cout << "\n en utilisant la transmission par référence:" << endl;
    a = 5; b = 10; 
    cout << "Avant : a = " << a << endl;
    incrmt_ref(a);
    cout << "Apres incrementer_reference : a = " << a << endl;

    cout << "Avant permutation : a = " << a << ", b = " << b << endl;
    permut_ref(a, b);
    cout << "Apres permuter_reference  : a = " << a << ", b = " << b << endl;

    return 0;
}
