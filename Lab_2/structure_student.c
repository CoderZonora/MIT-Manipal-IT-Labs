#include<stdio.h>
struct student{
    char name[100];
    int rollno;
    char grade;

};
void read(struct student s1[],int n){
    for(int i=0;i<n;i++){
        printf("Enter the name of the student: \n");
        scanf("%s",&s1[i].name);
        printf("Enter the roll no of the student: \n");
        scanf("%d",&s1[i].rollno);
        fflush(stdin);
        printf("Enter the grade of the student: \n");
        scanf("%c",&s1[i].grade);
    }
}

void display(struct student s1[],int n){
    for(int i=0;i<n;i++){
        printf("Student Name %d",i+1,s1[i].name);
        printf("Roll No: %d \n",s1[i].rollno);
        printf("Student grade: %c \n",s1[i].grade);
    }
}

void sort(struct student s1[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int min = i;
            if(s1[i].rollno>s1[j].rollno){
                min = j;
            }
        }
		temp = s1[min].rollno;
		s1[min].rollno = s1[i].rollno;
        s1[i].rollno = temp;
    }
    printf("The structure is sorted \n");
}
int main(){
struct student s1[40];
int n;
printf("Enter value of n: ");
scanf("%d",&n);
read(s1,n);
display(s1,n);
sort(s1,n);
display(s1,n);
return 0;}
