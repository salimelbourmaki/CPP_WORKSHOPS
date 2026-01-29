#include <iostream>
using namespace std;

void compteur() {
    static int c = 0; 
    c++;
    cout << "appel numero " << c << endl;
}

int main() {
    compteur();
    compteur();
    compteur();  
    return 0;
}
