#include<stdio.h>
int main(){
int i=0,pos,s1_len=0,s2_len=0;
char s1[100],s2[50],s3[100];
printf("Enter string: ");
gets(s1);
printf("Enter substring: ");
gets(s2);
printf("Enter position: ");
scanf("%d",&pos);
while(s1[s1_len]!='/0'){
    s1_len++;
}
while(s2[s2_len]!='/0'){
    s2_len++;
}

for(i=s1_len;i>=pos;i--){
    s1[i+s2_len] = s1[i];
}
for(i=0;i<s2_len;i++){
    s1[i+pos] = s2[i];
}
i=0;
while(s1[i]!='\0'){
    printf("%s",s1[i]);
}
return 0;
}
