#include<stdio.h>
int main(){
char a[100],b[100];
printf("Enter string a: ");
gets(a);
printf("Enter string b: ");
gets(a);
int flag = 0;
for(int i=0;a[i]!='/0';i++){
    for(int j=0;b[j]!='\0';j++){
        if(a[i]==b[j]){
            flag = 1;
        }
        else{
        flag = 0;
        }
    }
}
if(flag){
    printf("The strings are same: ");
}
else{
    printf("The strings are not same: ");
}
return 0;
}
