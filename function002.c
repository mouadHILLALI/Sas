#include <stdio.h>
#include <math.h>
#include <string.h>
int min(int a , int b ){

return (a<b)? a : b ; 
}
int max(int c , int d){
return (c>d)? c : d ;
}

/*void hello ( char[],int);*/ 
int main()
{
/*
char name [] = "mouad";
int age = 22;
hello(name , age);
}
void hello ( char name[] , int age){
printf("hello %s %d", name ,age);
}
*/
/*int main()
{
char name [10];
printf("enter your name:" );
scanf("%s", &name);


int age = 22;
strrev(name); //to reverse a string
printf("%s" , name);

*/

 /*char name [6];
printf("enter your name:");
scanf("%s", &name);
while (strlen(name)>6)
{
    printf("error\n");
    
    if (strlen(name)>6)
    {
        printf("enter your name:");
        scanf("%s", &name);
    }


}
if (strlen(name)<=6)
{
    printf("hello %s ", name);

}
*/
int a , b, c , d ;

printf ("enter n:");
scanf("%d" , &a);
printf ("enter n:");
scanf("%d" , &b);
printf ("enter n:");
scanf("%d" , &c);
printf ("enter n:");
scanf("%d" , &d);

int result1 =  min(a,b);
int result2 = max(c,d);


printf("the min is  %d" , result1);
printf(" the max is %d" , result2);

 
 
 
}
