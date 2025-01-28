#include<stdio.h>
int multi(int a,int b){
    if(b==0){
        return 0;
    }
    else{
        return  a+ multi(a,b-1);
    }
}
int main(){
    int a,b;
    printf("Enter numbers a and b: ");
    scanf("%d %d",&a,&b);
    int ans=multi(a,b);
    printf("%d",ans);
 return 0;
}
