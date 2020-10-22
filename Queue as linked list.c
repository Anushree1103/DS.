#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void insert(int val);
void display();
void delete();
void peep();

struct node * front=NULL;
struct node * rear=NULL;

int main()
{
    while(1)
    {
        int ch,val;
        printf("\nMenu:\n1.Insert\n2.Delete\n3.Peep\n4.Display\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter data:");
                   scanf("%d",&val);
                   insert(val);
            break;
            case 2:delete();
            break;
            case 3:peep();
            break;
            case 4:display();
            break;
            case 5:exit(0);
        }
    }
    return 0;
}

void insert(int val)
{
    struct node * newnode;
    newnode= (struct node *)malloc(sizeof(struct node*));
    newnode->data=val;
    newnode->next=NULL;
    if(rear!=NULL)
    {
        rear->next=newnode;
        rear=newnode;
    }
    else
    {
        rear=front=newnode;
    }
}

void delete()
{
    struct node* ptr;
    ptr=front;
    if(front==NULL)
        printf("\nThe queue is empty!!\n");
    else
    {
        printf("Value deleted from queue=%d",front->data);
        if(front==rear)
        {
            front=rear=NULL;
        }
        else
        {
            front=front->next;
        }
        free(ptr);
    }
}

void peep()
{
    if(front==NULL)
        printf("Queue is empty!");
    else
    {
        printf("The front element of the queue is: %d", front->data);
    }
}

void display()
{
    struct node * ptr;
    ptr=front;
    if(ptr==NULL)
    {
        printf("Queue is Empty!!");   
    }
    else
    {
        printf("The Queue elements are: \n");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
