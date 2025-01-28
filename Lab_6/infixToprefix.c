#include<stdio.h>
#define MAX_SIZE 100
typedef struct{
    int top;
    char arr[MAX_SIZE];
}Stack;

int isFull(Stack *s){
    if(s->top == MAX_SIZE - 1){
        return 1;
    }
    return 0;
}
int isEmpty(Stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

void push(Stack *s, char item){
    if(isFull(s)){
        printf("Cannot push");
        return;
    }
    s->top++;
    s->arr[s->top] = item;
}

char pop(Stack *s){
    if(isEmpty(s)){
        printf("Cannot pop");
        return '/0';
    }
    char poppedElement = s->arr[s->top];
    s->top--;
    return poppedElement;
}
char peek(Stack *s){
    if(isEmpty(s)){
        printf("Cannot peek");
        return '/0';
    }
    char peekElement = s->arr[s->top];
    return peekElement;
}
int precedence (char ch)
{
  switch (ch)
    {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case ')':
        return 0;
    case '^':
      return 3;
    default:
        return -1;
    }
}
void infixToprefix(Stack *s,char *infix,char *postfix){
    char temp,x;
    int i=0,j=0;
    while(infix[i]!='/0'){
        temp=infix[i];
        if(isalnum(temp)){
            prefix[j++]=temp;
        }
        else if(temp==')')
         push(temp);
        else if(temp=='(')
            {
         while((x=pop())!=')')
         {
          prefix[j++]=x;
           }
          }
        else
        {  while(prcd(a[top])>=prcd(temp))
            {prefix[j++]=pop();}
                push(temp);
        }
        i++;
    }
    while(top!= -1)
    prefix[j++]=pop();
    prefix[j]='\0';
    strrev(prefix);
}
    }
}
int main(){

return 0;}
