#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;
 
void display(node*);
node * insert_beg(node *);
node * insert_end(node *);
node * insert_at(node *);
node * insert_before(node *);
node * insert_after(node *);

int main()
{
    struct node * start=NULL;
    int ch;
    while(1)
    {
        printf("\nMenu:\n1. insert_beg\n2. insert_end\n3. insert_at\n4. insert_before\n5. insert_after\n6. display\n7.Exit "); 
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:start=insert_beg(start);
            break;
            case 2:start=insert_end(start);
            break;
            case 3:start=insert_at(start);
            break;
            case 4:start=insert_before(start);
            break;
            case 5:start=insert_after(start);
            break;   
            case 6:display(start);
            break;   
            case 7:exit(0);
        }
    }
    
}


node * insert_beg(node *start)
{
    node *newnode=malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=start;
    start=newnode;
    return start;
}

node * insert_end(node * start)
{
    node *ptr;
    node *newnode=(node *)malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
    return start;
}

void display(node* start)
{
    node * ptr;
    ptr=start;
    if(ptr==NULL)
    {
        printf("Empty list");
    }
    printf("\nElements of the list:\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

node * insert_at(node *start)
{
    node *ptr1, *ptr2;
    int pos,count=1;  
    node *newnode=(node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("Enter position at which to insert:");
    scanf("%d",&pos);
    
    if(start==NULL&&pos>1)
    {
        printf("List empty cant insert at position ");
    }
    if(pos==1)
    {
        newnode->next=start;
        start=newnode;
    }
    else
    {
        ptr1=start;
        ptr2=start;
        while(ptr2!=NULL&&count<pos)
        {
            count=count++;
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        if(count==pos)
        {
            newnode->next=ptr2;
            ptr1->next=newnode;
        }
        else
        {
            printf("Cant insert at position %d",pos);
        }
    }
    return start;
    
}

node *insert_before(node *start)
{
    node *ptr1, *ptr2;
    int val;
    node *newnode=(node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("Enter Value of node before which to insert node");
    scanf("%d",&val);
    if(start==NULL)
    {
        printf("List empty cant insert!");
    }
    else
    {
        ptr1=ptr2=start;
        while(ptr2!=NULL&&ptr2->data!=val)
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        if(ptr2==NULL)
        {
            printf("Value not found!! Cant insert!");
        }
        else
        {
            newnode->next=ptr2;
            if(ptr1==ptr2)
            {
                start=newnode;
            }
            else
            {
                ptr1->next=newnode;
            }
        }
    }
    return start;
}

node * insert_after(node * start)
{
    node *ptr;
    int val;
    node *newnode=(node *)malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("Enter Value of node after which to insert node");
    scanf("%d",&val);
    if(start==NULL)
    {
        printf("List empty cant insert!");
    }
    else
    {
        ptr=start;
        while(ptr!=NULL&&ptr->data!=val)
        {
            ptr=ptr->next;
        }
        if(ptr!=NULL)
        {
            newnode->next=ptr->next;
            ptr->next=newnode;
        }
        else
        {
            printf("Value not found! Camt insert !");
        }
    }
    return start;
    
}

