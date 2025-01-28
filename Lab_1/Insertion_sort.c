#include<stdio.h>
void insert_Sort(int arr[],int n){
int i,j,temp,pos;
for(i=1;i<n;i++){
    temp = arr[i];
    for(j = i-1;j>=0 && arr[j]>temp;j--){
        arr[j+1] = arr[j];
    }
    arr[j+1] = temp;
}
printf("The array is sorted");
}
int main(){
int arr[20],n;
printf("Enter the number of elements for the array: ");
scanf("%d",&n);
printf("Enter the elements in the array: ");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
insert_Sort(arr,n);
for(int i=0;i<n;i++){
    printf("%d",arr[i]);
}
return 0;
}
