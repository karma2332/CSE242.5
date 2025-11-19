//Write a program in C to take an array with odd number of elements and insert a new element in position 5 after deleting the 4th position value  


#include <stdio.h>
int main(){
int size,elements,poss,poss2,newElement;
printf("Input the size of the array");
scanf("%d",&size);

printf("input how many elements in odd value");
scanf("%d",&elements);
if(elements%2==0){
    printf("the value of elements is invalid");

}

printf("Put the values in the array:");
int arr[size];
for(int i = 0;i < elements;i++){
    scanf("%d",&arr[i]);
}
printf("Now input the position you want to delete");
scanf("%d",&poss);
poss--;

for(int i = poss;i < elements -1 ;i++){
    arr[i]=arr[i+1];
}
elements--;

for(int i = 0;i < elements;i++){
    printf("%d  ",arr[i]);}



printf("\n Now input the position you want to insert the new element");
scanf("%d",&poss2);
poss2--;


for(int i = elements;i > poss2;i--){
    arr[i]=arr[i-1];
}
printf("input the new element: ");
scanf("%d",newElement);

arr[elements]= newElement;
elements++;

for(int i = 0;i < elements;i++){
    printf("%d ",arr[i]);}
return 0;
}
