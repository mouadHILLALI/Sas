#include <stdio.h>
#include <math.h>
#include <string.h>



int main () {
int n ,somme;
printf("entrer votre nombre:");
scanf("%d", &n);
if (n>100&&n<1000)
{
    int a = n/100;
    int b = n%100;
    int c = b/10; 
    int d = b%10;

    somme= pow(a,3)+pow(c,3)+pow(d,3);
    
    if (n==somme)
    {
          printf("%d est une armstrong", n);

    }
    if (n!=somme)
    {
        printf("%d cest pas un nombre armstrong", n);
    }
    
     
}


    
    }