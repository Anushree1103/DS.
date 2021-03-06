
#include <stdio.h>
#include<string.h>
#define size 50

float stack[size];
int top=-1;
float evaluate(char *);

void push(float val)
{
    if(top==size-1)
        printf("\nStack Full!!\n");
    else
    {
        top++;
        stack[top]=val;
    }
}

float pop()
{
    if(top==-1)
    {
        printf("\nStack Empty!!\n");
        return -1;
    }
    else
        return(stack[top--]);
}

int main()
{
    float ans;
    char postfix[50];
    printf("Enter the postfix expression: ");
    gets(postfix);
    printf("\nThe postfix expression is= %s",postfix);
    ans=evaluate(postfix);
    printf("\nAnswer after evaluation=%0.2f",ans);
   
}
 
float evaluate(char postfix[50])
{
    int i=0;
    float val;
    float a,b;
    while(postfix[i]!='\0')
    {
        if(isalpha(postfix[i]))
        {
            printf("\nEnter the value of%c: ",postfix[i]);
            scanf("%f",&val);
            push(val);
        }
        else
        {
            b=pop();
           
            a=pop();
           
            switch(postfix[i])
            {
                case '+': val=(a+b);
                break;
                case '-': val=(a-b);
                break;
                case '*': val=(a*b);
                break;
                case '/': val=(a/b);
                break;
            }
            push(val);
        }
        i++;
    }
    return pop();
}
