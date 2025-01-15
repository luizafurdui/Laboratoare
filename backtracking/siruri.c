#include <stdlib.h>
#include <stdio.h>
//Se citeşte un număr natural nenul n, apoi n numere naturale distincte. Să se afişeze, în ordine lexicografică,
// șirurile din cele n valori cu proprietatea că oricare două valori învecinate sunt prime între ele.
int a[101], n, x[10];
int visited[10]; 
void tipar(int k, int x[]) {
    for (int i = 1; i <= k; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void Ordonare() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}
int cmmdc(int a, int b)
{
        while(b!=0)
        {
            int r = a%b; 
            a = b; 
            b = r; 
        }

        return a; 
}
int ok(int k)
{
    for(int i = 1; i<k; i++)
    if(x[i] == x[k]) return 0; 

    if(k>1)
    {
        if(cmmdc(a[x[k]], a[x[k-1]]) != 1 ) return 0; 
        return 1;

    }
}
void back(int k )
{
    for(int i = 1; i<=n; i++)
    {

        x[k] = i;
        if(ok(k))
        {
            if(k==n) tipar(k,x); 
        }
        else
        back(k+1); 
        

    }
}
int main() {
     n = 4;
    int initial_values[] = {5, 3, 8, 5}; 

 
    for (int i = 0; i < n; i++) {
        a[i] = initial_values[i];
    }
    Ordonare();  
    back(1); 
  

    return 0;
}
