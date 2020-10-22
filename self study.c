#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

/*void count_of_nodes(struct node *head) {
    int count = 0;
    if(head == NULL)
       printf("Linked List is empty");
    struct node *ptr = NULL;
    ptr= head;
    while(ptr!=NULL) {              //code to print nodes
        count++;
                                  //  ptr = ptr->link;
        printf("%d \n",ptr->data);
        ptr = ptr->link;
    }
    printf("%d",count);
}
*/

/*
void add_at_end(struct node *head, int data) {
    struct node *ptr, *temp;
    ptr= head;
    
    temp = malloc(sizeof(struct node));
    
    temp->data = data;
    temp->link = NULL;
    
    while(ptr->link!= NULL) {

        ptr =ptr->link;
    }
    
    
    
    ptr->link=temp;
    
}
 */
 
/* 
struct node* add_beg(struct node* head, int d)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data=d;
    ptr->link = NULL;
    
    ptr->link = head;
 
    head = ptr;
    return head;
}
*/ 

/* 
void add_at_pos(struct node* head, int data, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;
    
    pos--;
    while(pos!=1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
    
}
*/

/*
struct node* del_first(struct node *head)
{
    if(head == NULL)
        printf("List is already empty!");
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);   
        temp = NULL;
    }
    return head;
   
}
*/

struct node* del_last(struct node *head)
{
    if(head == NULL)
        printf("List is Already empty!");
    else if(head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else 
    {
        struct node *temp = head;
        struct node *temp2 = head;
        while(temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link= NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}
 
int main()
{
    int m,d;
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    
    struct node *current = malloc(sizeof(struct node));
    current->data=99;
    current->link=NULL;
    head->link = current;
    
    current = malloc(sizeof(struct node));
    current->data=9;
    current->link=NULL;
    head->link->link = current;  
    
    //  head = add_beg(head,5);
    
    //  count_of_nodes(head);
    
    /*  printf("how many node do you want to add");
    scanf("%d",&m);
    while(m>0)
    {
        printf("Enter data");
        scanf("%d",&d);
        add_at_end(head, d);
        m--;
    } */  
    
    /* int pos, data;
    data = 4, pos = 2; 
    add_at_pos(head, data, pos); 
    */
    
    //  head = del_first(head);
    
    //  head = del_last(head);
    
    
    struct node *ptr = NULL;
    ptr= head;  
    
    
    while(ptr!=NULL) {     // code to print nodes
        printf("%d \n",ptr->data);
        ptr = ptr->link;
        
    }    
    return 0;
}




