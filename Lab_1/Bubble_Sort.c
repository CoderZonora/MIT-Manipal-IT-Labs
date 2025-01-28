#include<stdio.h>
int bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j = 0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("The array is sorted: \n");
    return 0;
}
int main(){
int arr[50],n;
printf("Enter the number of elements of the array: ");
scanf("%d",&n);
printf("Enter the elements of the array: ");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
bubbleSort(arr,n);
for(int i =0;i<n;i++){
    printf("%d",arr[i]);
}
}
