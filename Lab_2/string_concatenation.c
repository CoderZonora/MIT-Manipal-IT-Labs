#include<stdio.h>
int main(){
char a[100],b[100],c[200];
printf("Enter for string a: ");
gets(a);
printf("Enter for string b: ");
gets(b);
int a_len=0;
int b_len = 0;
while(a[a_len]!='\0'){
    a_len++;
}
printf("\n %d",a_len);
while(b[b_len]!='\0'){
    b_len++;
}
printf("\n %d",b_len);
for(int i=0;i<(a_len);i++){
    c[i] = a[i];
}
for(int j = 0;j<b_len;j++){
    c[a_len+j] = b[j];
}
fflush(stdin);
puts(c);

return 0;
}
