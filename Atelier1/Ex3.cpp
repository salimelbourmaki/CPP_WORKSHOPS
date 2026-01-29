#include <iostream>
using namespace std;

int main() {
    int n = 5, p = 9; 
    int q;
    float x;

    q = n < p;
    cout << "1) q = " << q << " /* 5 < 9 => vrai */" << endl;  /* on a bien 5 < 9 alors elle est vrai (1) */

    q = n == p;
    cout << "2) q = " << q << " /* 5 == 9 => faux */" << endl; /* 2) test égalité n == p -> faux (0) */

    /* 3) priorité : p % n + p > n
         p % n = 9 % 5 = 4 -> 4 + 9 = 13 > 5 -> vrai */
    q = p % n + p > n;
    cout << "3) q = " << q << " /* 9%5 + 9 > 5 => vrai */" << endl;

    /* 4) division entière stockée dans float -> 9/5 = 1 -> 1.0 */
    x = p / n;
    cout << "4) x = " << x << " /* division entière */" << endl;

    /* 5) conversion pour obtenir division réelle */
    x = (float)p / n;
    cout << "5) x = " << x << " /* 9.0/5 = 1.8 */" << endl;

    /* 6) (p + 0.5) / n */
    x = (p + 0.5) / n;
    cout << "6) x = " << x << " /* 9.5/5 = 1.9 */" << endl;

    /* 7) cast int avant division -> (int)9.5 = 9 -> 9/5 = 1 */
    x = (int)(p + 0.5) / n;
    cout << "7) x = " << x << " /* (int)9.5 = 9 => 9/5 = 1 */" << endl;

    /* 8 & 9) utilisation ternaire pour choisir entre n et p */
    q = n * (p > n ? n : p); /* p>n vrai => n*n */
    cout << "8) q = " << q << " /* n * (p>n ? n : p) => 5*5 = 25 */" << endl;

    q = n * (p < n ? n : p); /* p<n faux => n*p */
    cout << "9) q = " << q << " /* 5*9 = 45 */" << endl;

    return 0; 
}
