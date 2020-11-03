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
    
}
