#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct Stack{
	int top;
	char a[SIZE];
	}Stack;
Stack s;

int IsEmpty(){
	return s.top == -1;
	}
	
int IsFull()
{
	return s.top == SIZE-1;
}

void push(char x)
{
	if(IsFull())
	{
		return ;
	}
	s.top++;
	s.a[s.top] = x;
}
char StackTop()
{
	if(IsEmpty())
	{
		return 0;
	}
	return s.a[s.top];
}

char pop()
{
	if(IsEmpty())
	{
		return 0;
	}
	char x;
	x = s.a[s.top];
	s.top--;
	return x;
}

int in_pre(char x)
{
    if(x == '+' || x == '-')
        return 2;
    else if(x == '*' || x == '/')
        return 4;
    else if(x == '$')
        return 5;
    else if(x == '(')
        return 0;
    return 0;
}

int out_pre(char x){
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 3;
    else if(x == '$')
        return 6;
    else if(x == '(')
        return 7;
    else if(x == ')')
        return 0;
    return 0;
}
int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x =='$' || x =='(' || x ==')')
        return 0;
    return 1;
}

char * InToPost(char *infix)
{
    int i=0,j=0;
    int len = strlen(infix);
    char *postfix = (char *)malloc((len+2)*sizeof(char));
    while(infix[i]!='\0')
	{
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if(out_pre(infix[i]) == in_pre(StackTop())){
                pop();
                i++;
            }
            else if(out_pre(infix[i]) > in_pre(StackTop()))
                push(infix[i++]);
            else{
                postfix[j++] = pop();
            }
        }
    }
    while(!IsEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = malloc(sizeof(char) * 25);
   	printf("Enter the Infix Expression: ");
	gets(infix);
    push(' ');
    char *postfix = InToPost(infix);
    printf("\nPostfix Expression is: %s ",postfix);
    return 0;
}

