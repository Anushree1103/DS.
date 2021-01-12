/* To construct a Binary Search Tree */
#include <stdio.h>
#include<stdlib.h>

struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL , *t1;

void delete1();
void insert();
void delete();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
void search1(struct btnode *t, int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);

int main()
{
    int ch;
    printf("\nOPERATIONS: \n1. Insert an element into tree\n2. Delete an element from the tree\n3. Display\n4. Exit\n");
    
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
            break;
            case 2: delete();
            break;
            case 3: printf("\nInorder traversal: ");
                    inorder(root);
                    printf("\nPreorder traversal: ");
                    preorder(root);
                    printf("\nPostorder traversal: ");
                    postorder(root);
                    break;
            case 4: exit(0);
            default: printf("Wrong choice. Please enter correct choice");
            break;
        }
    }
}

/*To insert a node in the tree */
void insert()
{
    create();
    if(root == NULL)
        root = temp;
    else
        search(root);  
}

/*To create a node */
void create()
{
    int data;
    
    printf("Enter data of node to be inserted: ");
    scanf("%d",&data);
    temp = (struct btnode *)malloc(sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r =NULL;
}

/*Function to search the appropriate position to insert the new node */
void search(struct btnode *t)
{
    if((temp->value > t->value) && (t->r != NULL))
        search(t->r);
    else if((temp->value > t->value) && (t->r != NULL))
        t->r = temp;
    else if((temp->value < t->value) && (t->l != NULL))
        search(t->l);
    else if((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}

/*To check for the deleted node */
void delete()
{
    int data;
    
    if(root == NULL)
    {
        printf("No elements in a tree to delete");
        return;
    }
    printf("Enter the data to be deleted : ");
    scanf("%d",&data);
    t1 = root;
    
    search1(root, data);
}

/*Search for the appropriate position to delete the node */
void search1(struct btnode *t, int data)
{
    if((data > t->value))
    {
        t1 = t;  /*Store the parent node address*/
        search1(t->r, data);  /*search the right subtree*/
    }
    else if((data < t->value))
    {
        t1 = t;
        search1(t->l, data);  /*search the left sub tree*/
    }
    else if((data==t->value))
    {
        delete1(t);
    }
}

/*To delete  node*/
void delete1(struct btnode *t)
{
    int k;
    
    if ((t->l) && (t->r == NULL))   /*case 1: to delete eaf node*/
    {
        if(t1->l == t)
        {
            t1->l == NULL;
        }
        else
        {
            t1->r =NULL;
        }
        t = NULL;
        free(t);
        return;
        
    }
    /*Case2: To delete node having one left child*/
    else if(t->r ==NULL)
    {
        if(t1 == t)   /*deleting the root*/
        {
            root = t->l;
            t1 = root;
        }
        else if(t1->l == t)   /*It is the right child of its parent*/
            t1->l = t->l;
        else  /*It is the left chid of its parent*/
            t1->r = t->l;
            
        free(t);
        return;
    }

    /*Case2: To delete node having right child*/
    else if(t->l ==NULL)
    {
        if(t1 == t)   /*deleting the root*/
        {
            root = t->r;
            t1 = root;
        }
        else if(t1->r == t)   /*It is the right child of its parent*/
            t1->r =t->r;
        else  /*It is the left chid of its parent*/
            t1->l = t->r;
            
        free(t);
        return;
    }
    
    /*Case3: To delete node having two child*/
    else if((t->l != NULL) && (t->r != NULL))
    {
        if(t->r != NULL)
        {
            k = smallest(t->r);
        }
        
        search1(t->r, k);
        t->value = k;
    }
}

/*To find the smallest element in the right sub tree */
int smallest (struct btnode *t)
{
    if(t->l != NULL)
    {
        return(smallest(t->l));
    }
    else
        return(t->value);
}

/*To find the largest element in the left sub tree */
int largest (struct btnode *t)
{
    if(t->r != NULL)
    {
        return(largest(t->r));
    }
    else
        return(t->value);
}

/* recursive function to perform inorder traversal of tree */
void inorder(struct btnode *t)
{
    if(root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if(t->l != NULL)
        inorder(t->l);
    printf("%d ->", t->value);
    if(t->r != NULL)
        inorder(t->r);
}

/*To find the preorder traversal */
void preorder(struct btnode *t)
{
    if(root ==NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    printf("%d->", t->value);
    if(t->l != NULL);
        preorder(t->l);
    if(t->r != NULL)
        preorder(t->r);
}

/*To find the postorder traversal */
void postorder(struct btnode *t)
{
    if(root ==NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if(t->l != NULL);
        postorder(t->l);
    if(t->r != NULL)
        postorder(t->r);
    printf("%d->", t->value);
    
}
