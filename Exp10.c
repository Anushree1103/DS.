/* To construct a Binary Search Tree */
#include <stdio.h>
#include<stblib.h>

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
void search(struct btnode *t, int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);

int main()
{
    int ch;
    printf("")
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
    if(temp->value > t->value) && (t->r! = NULL))
        search(t->r);
    else if((temp->value >t->value) && (t->r == NULL))
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
    
    search(root, data);
}

/*Search for the appropriate position to delete the node */
void search1(struct btnode *t, int data)
{
    if((data->t->value))
    {
        t1 = t;  /*Store the parent node address*/
        search(t->r, data);  /*search the right subtree*/
    }
}

