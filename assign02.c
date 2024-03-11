#include <stdio.h>
int main()
{
/* int a;
 int v = 0 ;
 printf("enter a :");
 scanf("%d", &a);
 for ( int i=2 ; i<a ; i++)
 {
    if (a%i==0)
    {
        printf("cest pas un nombre premier");
        v++;
        break;
    }
 
  else{
    printf("cest un nombre premier");
    break;
  }
  }
 if (v==0)
 {
    printf("cest un nombre premier");
 }*/
 /*int n,inverse=0,chiffre;
printf("entrer n :");
scanf("%d" , &n);
 while (n>0)
 {
    chiffre = n%10;
    inverse= inverse*10 + chiffre;
    n/=10;
 
 }
  
 printf("%d" , inverse);
    return 0 ; 
 */
int n=1, somme=0, max=0 ;


while (n!=0)
{
    printf("entrer les series dentiers , pour finir entrer 0 :");
    scanf("%d", &n);
    while (n>100)
    {
        printf(" saisis une nombre inferieur a 100");
        scanf("%d", &n);
    }
    somme = somme + n ;
    if (n>max)
    {
        max = n ; 
    }
    
}

printf("la somme est %d et le max %d", somme, max)
 
 
 
 
 






 
}