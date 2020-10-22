#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;
 
void display(node*);

node * insert_end(node *); 

node * delete_beg(node *);
node * delete_end(node *);
node * delete_at(node *);
node * delete_before(node *);
node * delete_after(node *);

int main()
{
    int i;
    struct node * start=NULL;
    int ch;
    printf("Enter value for 10 nodes: \n");
    
    for(i=0;i<10;i++)
    {
        start=insert_end(start);
    }
    
    while(1)
    {
        printf("\nMenu:\n1. delete_beg\n2. delete_end\n3. delete_at\n4. delete_before\n5. detele_after\n6. display\n7.Exit "); 
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:start=delete_beg(start);
            break;
            case 2:start=delete_end(start);
            break;
            case 3:start=delete_at(start);
            break;
            case 4:start=delete_before(start);
            break;
            case 5:start=delete_after(start);
            break;   
            case 6:display(start);
            break;   
            case 7:exit(0);
            case 8: start=insert_end(start);
            break;
        }
    }
    
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
        return ;
    }
    printf("\nElements of the list:\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

node * delete_beg(node * start)
{
    if(start==NULL)
        printf("List Empty! can't delete");
    else
    {
        start=start->next;
    }
}

node * delete_end(node * start)
{
    node *ptr;
    if(start==NULL)
    {
        printf("List Empty! can't delete");
    }
    else
    {
        ptr=start;
        while(ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        free(ptr->next);
        ptr->next=NULL;
    }
    return start;
}

node * delete_at(node *start)
{
    node *ptr1, *ptr2;
    int pos, count=1;
    printf("Enter position from which to delete: ");
    scanf("%d",&pos);
    
    if(start==NULL)
    {
        printf("List Empty! can't delete");
    }
    if(pos==1)
    {
        ptr1=start;
        start=start->next;
        free(ptr1);
        
    }
    else
    {
        ptr1=start;
        ptr2=start;
        while(ptr2!=NULL && count<pos)
        {
            count=count++;
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        if(count==pos)
        {
            ptr1->next=ptr2->next;
            free(ptr2);
        }
        else
        {
            printf("Position doesnt exists!! Can't Delete!");
        }
    }
    return start;
}

node * delete_before(node *start)
{
    node *ptr1, *ptr2;
    int val;
    
    printf("Enter Value of node before which to delete node");
    scanf("%d",&val);
    if(start==NULL)
    {
        printf("List Empty! can't delete");
    }
    else
    {
        ptr1=ptr2=start;
        if(ptr2->data==val)
        {
            printf("This is the first node!! nothing to delete before this!!");
            return start;
        }
        while(ptr2->next!=NULL && ptr2->next->data!=val)
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        if(ptr2==start)
        {
            start=ptr2->next;
            free(ptr2);
        }  
        else if(ptr2->next==NULL)
        {
            printf("Value not found!! Cant delete!");
        }
        else
        {
            ptr1->next=ptr2->next;
            free(ptr2);
        }
    }
    return start;
    
}

node *delete_after(node * start)
{
    node *ptr1, *ptr2;
    int val;
    printf("\nEnter the value after which the node has to be deleted");
    scanf("%d",&val);
    if(start==NULL)
    {
        printf("List Empty! can't delete");
    }
    else
    {
        ptr1=ptr2=start;
        while(ptr1->data!=val && ptr1->next!=NULL)
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        if(ptr2==NULL)
        {
            printf("No such data to delete!! ");
        }
        else
        {
            ptr1->next=ptr2->next;
            free(ptr2);
        }
    }
    return start;
}

