#include<stdio.h>
int LinearSearch(int arr[],int key,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==key){

            return i;
        }
    }
        return -1;
}
int main(){
    int arr[10],n,key,i;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        printf("Enter the element: \n");
        scanf("%d",&arr[i]);
    }
    printf("\n Enter the key to be searched in the array: ");
    scanf("%d",&key);
        int ans = LinearSearch(arr,key,n);
        if(ans>=0){
            printf("The key was found");
        }
        else{
            printf("The key was not found");
        }
    return 0;
}
