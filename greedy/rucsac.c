#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int n=4;

struct  R {

    int greutate; 
    int val; 
    int ef;

}a[101]; 
void swap(struct R *x, struct R *y)
{
    struct R temp = *x;
    *x = *y;
    *y = temp;

}

void sort(struct R a[])
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].ef <   a[j].ef)
            {
                swap(&a[i], &a[j]); 
              

            }
        }

    }
}

void rucsac(int Gmaxim)
{
    int suma_max = 0; 
    int i = 0; 
    while(Gmaxim >0  && i<n)
    {
        if (Gmaxim - a[i].greutate >= 0) // il iau
        {
            suma_max += a[i].val; 
          
        }
        else
        {
            int valoare = (Gmaxim * a[i].val) / a[i].greutate; 
            suma_max += valoare; 
  
        }
        Gmaxim -= a[i].greutate;
        i++; 
    }

    printf("%d", suma_max); 

}
