#include <iostream>
using namespace std;

int main() {
    char c = '\x05';   // c'est 5 en code ASCII
    int n = 5;
    long p = 1000;
    float x = 1.25;
    double z = 5.5;

    cout << "1)  n + c + p = " << n + c + p << endl;   /* type:long car 'int + char + long' donne 'long' comme résultat' et la valeur:1010*/
    cout << "2)  2 * x + c = " << 2 * x + c << endl;   /* type: float car c'est une arithmétique flottante et la valeur: 7.5*/
    cout << "3)  (char) n + c = " << (char) n + c << endl; /*cast explicite vers char puis addition, donc type entier(int), la valeur: 10*/
    cout << "4)  (float) z + n/2  = " << (float) z + n/2 << endl; /*type float et la valeur: 7.5*/

    return 0; }

                            /*un cast est une conversion de type explicite,
                            c-à-d une manière de dire au compilateur de traiter 
                            une valeur comme si elle avait un autre type.*/