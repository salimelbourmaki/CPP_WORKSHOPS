#include <iostream>
using namespace std;

//A. avec la méthode des tableaux []
//la fonction max pourle plus grand entier 
 int max(int T[], int n) {
    int max = T[0];
    for(int i = 1; i < n; i++) {
        if(T[i] > max)
            max = T[i];
    }
    return max;
}

 //la fonction min pour le plus grand entier
int min(int T[], int n) {
    int min = T[0];
    for(int i = 1; i < n; i++) {
        if(T[i] < min)
            min = T[i];
    }
    return min;
}

int main() {
    int T[10];

    cout << "Veuillez saisir 10 entiers :" << endl;
    for(int i = 0; i < 10; i++) {
        cin >> T[i];
    }

    cout << " le plus grand entier = " << max(T, 10) << endl;
    cout << "le plus petit entier= " << min(T, 10) << endl;

    return 0;
}

//B. avec la méthode des pointeurs*

#include <iostream>
using namespace std;

// fonction pour trouver le maximum avec pointeur
int maxP(int* p, int n) {
    int max = *p;  // p pointe sur T[0]
    for(int i = 1; i < n; i++) {
        if( *(p + i) > max )
            max = *(p + i);
    }
    return max;
}

// Fonction pour trouver le minimum avec pointeur
int minP(int* p, int n) {
    int min = *p;
    for(int i = 1; i < n; i++) {
        if( *(p + i) < min )
            min = *(p + i);
    }
    return min;
}

int main() {
    int T[10];

    cout << "Entrez 10 entiers :" << endl;
    for(int i = 0; i < 10; i++) {
        cin >> T[i];
    }

    cout << "le plus grand = " << maxP(T, 10) << endl;
    cout << "le plus petit = " << minP(T, 10) << endl;

    return 0;
}
