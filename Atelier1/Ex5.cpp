#include <iostream>
using namespace std;

void remplir(int* arr, int n) {      /*Remplir via arithmétique de pointeurs*/
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> *(arr + i); 
    }}

void afficher(const int* arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << *(arr + i) << " ";
    cout << endl;}

int& trouverMax(int* arr, int n) {     /*Retourne une référence vers l'élément maximum*/
    int idxMax = 0;
    for (int i = 1; i < n; ++i)
        if (*(arr + i) > *(arr + idxMax))
            idxMax = i;
    return *(arr + idxMax);}

void inverser(int* arr, int n) {
    for (int i = 0; i < n / 2; ++i) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + n - 1 - i);
        *(arr + n - 1 - i) = temp;
    }}

int main() {
    int n;
    cout << "Entrez la taille du tableau : ";
    cin >> n;

    int* arr = new int[n]; /*allocation dynamique*/

    remplir(arr, n);

    cout << "Tableau original : ";
    afficher(arr, n); /*affichage initial*/

    int& maxRef = trouverMax(arr, n);
    cout << "Maximum trouvé = " << maxRef << endl; /*trouver le maximum via référence*/

    cout << "On ajoute +10 au maximum..." << endl; /*modifier le maximum via référence*/
    maxRef += 10;

    cout << "Après modification : ";
    afficher(arr, n);

    inverser(arr, n);
    cout << "Tableau inversé   : ";
    afficher(arr, n); /*// l'affichage du tableau inverse*/

    delete[] arr; /*c'est pour liberer la memoire*/

    return 0; }

