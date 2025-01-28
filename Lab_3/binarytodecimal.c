#include<stdio.h>
#define MAX_SIZE 100
struct Stack{
    int top;
    int stck[MAX_SIZE];
};
void initialize(struct Stack *stack){
stack->top = -1;
}
void push(struct Stack *stack,int element){
    if(stack->top == MAX_SIZE-1){
        printf("Stack overflow, cannot push %d",element);
    }
    stack->top++;
    stack->stck[stack->top]=element;
}
int pop(struct Stack *stack){
if(stack->top == -1){
    printf("\n cannot pop stack, it is empty");
    return -1;
}
    int poppedElement = stack->stck[stack->top];
    stack->top--;
    return poppedElement;
}
int isEmpty(struct Stack *stack){
    if(stack->top == -1){
        return 1;
    }
    else{
        return 0;
}
}
int peek(struct Stack *stack){
if(stack->top==-1){
    printf("Stack is Empty,cannot peek");
    return -1;
}
    return stack->stck[stack->top];
}
int main(){
struct Stack stack;
initialize(&stack);
int num,rem;
int base;
printf("Enter a decimal number: ");
scanf("%d",&num);
printf("Enter a base: ");
scanf("%d",&base);
while(num>=1){
    rem = num%base;
    if(rem>=10){
        rem = rem - 10;
        rem +=65;
    }
    push(&stack,rem);
    num = num/base;
}
while(!isEmpty(&stack)){
        if(peek(&stack)>=65){
           printf("%c",pop(&stack));
       }
    printf("%d",pop(&stack));
}
return 0;
}
