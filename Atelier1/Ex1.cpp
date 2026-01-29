#include <iostream>
using namespace std;

int main() {
    char c = '\x01';     /* \x01 en code ASCII est 1 */ 
    short int p = 10;    /* 10 est un entier court */ 

    cout << "1)  p + 3 = " << p + 3 << endl;         /*type: entier (int) et la valaur: 10+3 =13 */
    cout << "2)  c + 1 = " << c + 1 << endl;  /* entier et la valeur: 1 + 1 = 2 */
    cout << "3)  p + c = " << p + c << endl;         /* entier et la valeur: 10 + 1 = 11 */
    cout << "4)  3*p + 5*c = " << 3*p + 5*c << endl; /* entier et la valeur: 3*10 + 5*1 = 35 */

    return 0; } 