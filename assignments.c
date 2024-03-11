#include <stdio.h>
#include <math.h> 
#include <string.h>
int main (){
/*char nom[10];
char prenom[10];
int age ; 
char sexe [10];
int numero  [10];
 
printf("entrer votre nom:");
scanf("%s",&nom);
printf("entrer votre prenom:");
scanf("%s",&prenom);
printf("entrer votre age :");
scanf("%d",&age);
printf("votre sexe:");
scanf("%s",&sexe);
printf("votre numero:");
scanf("%d", &numero);
if (numero>=10)
{
    printf("error a number cannot exceed ten numbers");
}



return 0 ;
*/
/*double F ,C;
printf("entrer la chaleur en F :");
scanf("%lf",&F);
C=(F-32)/1.8;
printf("%.2lf",C);
if (C<=15)
{
    printf(" tres froid");
}
else if (C>=15 && C<=25)
{
     printf(" froid");
    
}
else if (C>=26&& C <=35)
{
     printf(" chaud");
}
else{
     printf(" tres chaud");
}

return 0 ;
*/
/*int a , b ;
float result;
printf("entrer a :");
scanf("%d",&a);
printf("entrer b :");
scanf("%d",&b);
result = a*b ;
printf("%.2f" , result);
return 0 ;
*/


/*float a , b , c , result ;
printf("entrer a :");
scanf("%f", &a);
printf("entrer b :");
scanf("%f", &b);
printf("entrer c :");
scanf("%f", &c); 

result = (a+b+c)/3;
printf("%.2f", result);
return 0 ;*/


/*int  x1  , x2 ,y1,y2 ;
printf("entrer les cordonnes de M x1,y1 :");
scanf("%d %d" , &x1, &y1);
printf("entrer les cordonnes de N x2, y2:");
scanf("%d  %d", &y1 ,&y2);

float result = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
printf("%f", result);

return 0 ;*/

/*int number , a, b , c ,d ; 
printf("enter the number :");
scanf("%d",&number);
a = number/100 ; 
b= number%100;
c = b/10;
d=b%10;
printf("the inverse num is  %d%d%d",d,c,a);
return 0 ; */



/*float R;
printf("enter R:");
scanf("%f", &R);
float result = R*M_PI*2;
printf("%.2f", result);
return 0 ;*/






/*int a , b , c;
printf("enter a :");
scanf("%d", &a);
do
{
     b = a/8;
} while (b!=0);
printf("%d" , b);
return 0 ;

*/

// les boucles 


/*int a , n;
n=1;
printf("enter a :");
scanf("%d" , &a);                      //first chalenge
while (n<=10)
{
 int result=  a*n;
 printf("%d\n" ,result);
 n++;
} 
return 0 ;
*/



/*int i,z;
z=1;
printf("enter i :");
scanf("%d",&i);
for (i ; i < 30; i++)
{ for ( z*i; z < 40; z++)
     {
          printf(" *\n ");
     }
     
}
return 0 ;
*/
/*int a,b ; 
printf("enter a :");
scanf("%d",&a);
b=a%2;
if (b==0)
{
     printf(" a is an even number");

}
else{
     printf("a is an odd number");
}
return 0 ;
*/
/*char voyelle ;
printf("entrer le voyelle:");
scanf("%c", &voyelle);
voyelle = toupper(voyelle);
switch (voyelle)
{
case 'A':
     printf("cest une voyelle");
     break;
     case 'E':
     printf("cest une voyelle");
     break;
     case  'U':
     printf("cest une voyelle");
     break;
     case  'I':
     printf("cest une voyelle");
     break;
     printf("cest une voyelle");
     case  'Y':
     printf("cest une voyelle");
     break;
     printf("cest une voyelle");
     break;


default: printf("cest pas une voyelle");
     break;

}
 return 0 ;
*/




/*int a , b ; 
printf("enter a :");
scanf("%d", &a);
printf("enter b :");
scanf("%d", &b);
float result= (float) a/b;
printf("%.2f" , result);
return 0 ;*/



/*int a , b , sum;
printf("enter a and b :");
scanf("%d" , &a);
scanf("%d" , &b);
sum = a*b;
if (a==b)
{
     sum= ((a*b))*3;
     
}
printf("%d" , sum);
return 0 ; */

/*float b , a , c ;
printf("enter b and a and c :");
scanf("%f %f %f" ,&b,&a,&c);

float delta = pow(b,2)-4*a*c;
if (delta>0)
{
     printf("Delta=%f", delta);
     float x1 = (-b-sqrt(delta))/(2*a);

     float x2 = (-b+sqrt(delta))/(2*a);
     printf("x1=%f x2=%f" , x1, x2);
}
else if (delta==0)
{
     printf("Delta=%f", delta);
     (int) b , a ; 
     float x = (-b)/(2*a);
     printf("x=%f " , x);
}
else{
     printf("the equation have no solution");
}


return 0 ; */


int year, answer ;
char choice[20];
printf("enter the year :");
scanf("%d", &year);
year= 365* (year-(year-1));
printf("enter your choice :");
scanf("%s", &choice);
switch (choice[20])
{
case "months":
      answer =  year/12;
     printf("%d", answer);
     break;
     case "days":
      answer =  year;
     printf("%d", answer);
     break;
     case "hours":
      answer =  year/24 ;
     printf("%d", answer);
     break;
     case "minutes":
      answer =  year*24*60;
     printf("%d", answer);
     break;
     case "seconds":
      answer =  year*24*60*60;
     printf("%d", answer);
     break;



default: printf("this option is not available");
     break;

}
return 0 ; 
















}