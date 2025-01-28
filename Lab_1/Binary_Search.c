#include<stdio.h>
int binarySearch(int arr[],int key,int low,int high){
    int mid = (low+high)/2;
    while(low<=high){
                if(arr[mid]==key){
        return mid;
    }
        if(arr[mid]>key && arr[mid]!=key){
            high = mid-1;
        }
        if(arr[mid]<key){
            low = mid+1;
        }
    }
    return -1;
    }
int main(){
int arr[50],key,n;
printf("Enter the number of elements of the array: ");
scanf("%d",&n);
printf("Enter the elements of the array: ");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("Enter the key to be searched in the array: ");
scanf("%d",&key);
int ans = binarySearch(arr,key,0,n-1);
if(ans>0){
    printf("The key was found at %d position",ans+1);
}
else{
    printf("The key was not found");
}
return 0;
}
