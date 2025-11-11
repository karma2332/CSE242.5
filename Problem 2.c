//Print an Array of 10 Elements; take inputs of the Size and
//Element dynamically (take the size and elements different)
#include <stdio.h>
int main(){
int n,m;
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

return 0;
}
