#include<stdio.h>
//RECURSIVE BINARY SEARCH
int binary_search(int arr[],int n,int key,int high,int low){
int mid = (low+high)/2;
if(arr[mid]==key){
    return mid;
}
if(arr[mid]>key){
    return binary_search(arr,n,key,mid-1,low);
}
if(arr[mid]<key){
    return binary_search(arr,n,key,high,mid+1);
}
return -1;
}
int main(){
int arr[20],n,key;
printf("Enter the number of elements: ");
scanf("%d",&n);

printf("Enter the elements: ");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("Enter the key");
scanf("%d",&key);
int ans = binary_search(arr,n,key,n-1,0);
if(ans>=0){
    printf("The key was found at position %d",ans+1);
}
else{
    printf("The key was not found");
}
}
