#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	char bname[50];
	int pages;
	float price;
}book;
typedef struct node
{
	book data;
	struct node *next;
}node;

void printbook(book b);
void display(node *);
node * push(node*);
node * pop(node *);
void peep (node *);


int main()
{
	int i;
	struct node * top=NULL;
	int ch;
	
	while(1)
	{
		printf("\nMenu:\n1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:top=push(top);
            break;
            case 2:top=pop(top);
            break;
            case 3:peep(top);
            break;
            case 4:display(top);
            break;
            case 5:exit(0);
        }
    }
}

void display(node* top)
{
    node * ptr;
    ptr=top;
    if(ptr==NULL)
    {
        printf("Empty stack");
        return;
    }
    printf("\nElements of the stack: \n");
    while(ptr!=NULL)
    {
        printbook(ptr->data);
        ptr=ptr->next;
    }
}

node * push(node * start)
{
    node *newnode=malloc(sizeof(node));
    printf("Enter book details:\n");
	printf("Enter book name:");
	gets(newnode->data.bname);
	gets(newnode->data.bname);
	printf("Enter the no. of pages:");
	scanf("%d", &newnode->data.pages);
	printf("Enter the price:");
	scanf("%f", &newnode->data.price);
    newnode->next=start;
    start=newnode;
    return start;
}

void printbook(book b)
{
	printf("\nBoook name=%s, pages=%d, price=%0.2f",b.bname, b.pages, b.price);
}

node * pop(node *top)
{
    node *ptr;
    if(top==NULL)
        printf("List empty!! Cant delete!!");
    else
    {
        ptr=top;
        top=top->next;
        printf("Element popped=");
		printbook(ptr->data);
        free(ptr);
    }
    return top;
    
}

void peep(node * top)
{
    if(top==NULL)
        printf("Stack Empty!!");
    else
    {
        printf("Element at top=");
		printbook(top->data);
    }
    
}

