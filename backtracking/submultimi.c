#include <stdio.h>
#include <stdlib.h>
// . Generaţi o combinaţie de elemente din array (dacă există) astfel
// încât produsul elementelor să fie mai mare sau egal cu S şi
// produsul să fie cât mai apropiat posibil ca valoare de S.
int n = 4; 
int arr[101] = {0, 10, 15, 20, 25}; 
int k; 
int x[101]; 
int vectorSolutie[101], lengthVectorSolutie = 0; 
int S = 40; 
int diferentaMinima = 100; 

void afisareSolutie() {
    printf("Solutia gasita:\n");
    for (int i = 1; i <= lengthVectorSolutie; i++) {
        printf("%d ", vectorSolutie[i]);
    }
    printf("\n");
}

void retine(int k) {
    int s = 0; 

    for (int i = 1; i <= k; i++) {
        s += arr[x[i]];
    }


    if (s >= S) {
        if (s - S < diferentaMinima) { // Diferența minimă față de S
            diferentaMinima = s - S; 
            lengthVectorSolutie = k; 

            for (int i = 1; i <= k; i++) {
                vectorSolutie[i] = arr[x[i]];
            }
        }
    }
}

void back(int k) {
    for (int i = x[k - 1] + 1; i <= n; i++) {
        x[k] = i; 
        retine(k); 
        back(k + 1);
    }
}

int main() {
    // Pornim recursia de la nivelul 1
    x[0] = 0; // Inițializare pentru a începe combinațiile
    back(1);

    // Afișăm soluția găsită
    if (lengthVectorSolutie > 0) {
        afisareSolutie();
    } else {
        printf("Nu exista solutie.\n");
    }

    return 0;
}
