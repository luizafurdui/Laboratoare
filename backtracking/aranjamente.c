#include <stdio.h>
#include <stdlib.h>

int n = 4;
int p = 3; 
int x[101]; 
void afisare(int k)
{
    for(int j = 1 ; j <= k ; j ++)
     printf("%d ", x[j]); 

     printf("\n"); 
}

int solutie(int k)
{
    for(int i = 1; i<k; i++)
    {
        if(x[i] == x[k]) return 0; 
    }
    return 1; 


}
void aranjamente(int k)
{
    for(int i = 1; i<=n; i++)
    {
        x[k] = i; 

        if(solutie(k))
        {
            if(k==p) afisare(k);
            else
            aranjamente(k+1);  
        }
      
    }
}
int main()
{
    aranjamente(1); 
    return 0; 
}