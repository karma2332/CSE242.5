//Declare an Array, take Size, Elements dynamically. 
//Then print Odd elements from the Array.

#include <stdio.h>
int main(){
int n,m,even;
printf("Enter the size of the array : ");
scanf("%d",&n);

printf("Enter how many number will be there 0<=%d: ",n);
scanf("%d",&m);

int myNum[n];
printf("Enter the %d values ",m);
for(int i = 0;i < m;i++){
        scanf("%d",&myNum[i]);}


printf("The %d values of the array are: ",m);
for(int i = 0;i < m;i++){
     printf("%d ",myNum[i]);}

 printf("\nOdd elements from the array are: ");
    for (int i = 0; i < m; i++) {
        if (myNum[i] % 2 == 1) { 
            printf("%d ", myNum[i]);
        }

    }

return 0;
}
