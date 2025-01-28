#include<stdio.h>
int main(){
char str[100];
printf("Enter a string: \n");
gets(str);
int i=0;
while(str[i]!='\0'){
    i++;
}
printf("The length of the string is %d",i);
return 0;
}
