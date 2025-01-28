#include<stdio.h>
void selectSort(int arr[], int n) {
    int temp, min;
    for (int i = 0; i < n - 1; i++) {
        min = i;  
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
				{  min = j;}
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int arr[50],n;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
