#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
struct Stack{
int top;
char stck[MAX_SIZE];
};
void initialize(struct Stack *stack){
    stack->top = -1;
}
void push(struct Stack *stack,char a){
if(stack->top==MAX_SIZE-1){
    printf("Stack overflow,cannot push %d \n",a);
}
stack->top++;
stack->stck[stack->top] = a;
}
int pop(struct Stack *stack){
    if(stack->top==-1){
        printf("Stack is empty,cannot pop");
        return -1;
    }
    int poppeditem = stack->stck[stack->top];
    stack->top--;

    return poppeditem;
}
int peek(struct Stack *stack){
if(stack->top==-1){
    printf("Stack is empty, cannot peek");
    return -1;
}
return stack->stck[stack->top];
}

int main(){
    struct Stack st;
    char s[MAX_SIZE];
    initialize(&st);
    printf("Enter value of string: ");
    scanf("%s",&s);
    int flag = 0;
    for(int i=0;s[i]!='\0';i++){
        char b = s[i];
        push(&st,b);
    }
    int n = strlen(s);
    for(int i=0;i<(n/2);i++){
        if(pop(&st) == s[i]){
            flag = 1;
        }
        else{
            flag = 0;
        }
    }

    if(flag){
        printf("The string is a palindrome!");
    }
    else{
        printf("The string is not a palindrome");
}
return 0;
}

