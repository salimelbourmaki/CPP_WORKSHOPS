#include <iostream>
using namespace std;

int main() {
    int i, j, n;

    i = 0; /*A : post-incrément, c-a-d n reçoit l'ancienne valeur, i incrémente après*/
    n = i++;
    cout << "A : i = " << i << "    n = " << n << endl; /*i=1, n=0*/

    i = 10;
    n = ++i; /* B : pré-incrément, c-a-d i incrémente avant l'affectation*/
    cout << "B : i = " << i << "   n = " << n << endl; // i=11, n=11

    i = 20;
    j = 5;    /* C : mélange post et pré -> ++j appliqué avant multiplication. car ++j -> 6 ; i++ -> valeur 20 utilisée, i devient 21 après. */
    n = i++ * ++j; 
    cout << "C : i = " << i << "   j = " << j << "   n = " << n << endl;

    i = 15;
    n = i += 3; /*D : opérateur += retourne la nouvelle valeur et  i = 18 ; n = 18*/
    cout << "D : i = " << i << "   n = " << n << endl;

    i = 3;
    j = 5;
    n = i *= --j; /* E : combinaison *= et pré-décrément ; --j -> 4 ; i = 3*4 = 12 ; n = 12*/
    cout << "E : i = " << i << "   j = " << j << "   n = " << n << endl;
    
    return 0; }