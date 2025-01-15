#include <stdio.h>
#include <stdlib.h>

int x[10], n, p[10]; 
int nr = 2; 
n= 3; 

void afisare(int k, int x[]) {
    for (int i = 1; i <= k; i++) {
        printf("%d ", x[i]); 
    }
    printf("\n");
}


void combinari(int k )
{
    for(int i = x[k-1] +1 ; i<=n; i++)
    {
        x[k] = i; 
        if(k==nr)
        afisare(k,x); 
        else
        combinari(k+1); 
    }
}
void back(int k) {
    for (int i = 1; i <= n; i++) {
        if (!p[i]) { 
            x[k] = i; 
            p[i] = 1; 

            if (k < n) {
                back(k + 1);
            } else {
                afisare(k,x); 
            }

            p[i] = 0; 
        }
    }
}

int main() {


    back(1); 
    printf("\n"); 
    combinari(1); 
   
     
    return 0; 
}
