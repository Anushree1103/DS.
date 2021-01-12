
#include<stdio.h>
#define size 5

struct book
{
   char name[50];
   int pages;
   float price;
};

typedef struct book book;

book stack[size]; 
int top=-1;

book getbookdetails();
void push(book b);
book *pop();
void peep();
void display();
void show(book b);


int main()
{  
   int choice;
   book *bp;
   book b;
   
   while(1)
   {
     printf("\n1. Push 2. Pop 3. Peep 4. Display 5. Exit\nEnter your choice:");
     scanf("%d",&choice);
     switch(choice)
	 {
	   case 1:printf("Enter details of the book:\n");
	          b=getbookdetails();
			  push(b);
	          break;
       case 2:
	          bp=pop(); 
	          if(bp!=NULL)
			  {
			    printf("\nBook removed is:");
				show(*bp);
			  }
              break;
	   case 3:
	          peep();
	          break;
	   case 4:
	          display();
	          break;
	   case 5:return;
	  
     }
	 
   }

}

book getbookdetails()
{
   book b;
   printf("Enter name of the book:");
   scanf("%s",&b.name);
   printf("Enter No.of pages:");
   scanf("%d",&b.pages);
   printf("Enter price:");
   scanf("%f",&b.price);
   return b;
}

void show(book b)
{
   printf("\nBook name=%s, pages=%d, price=%f \n",b.name, b.pages, b.price);
}


book *pop()
{
   if(top==-1)
   {
     printf("\nStack Empty!!\n");
   }
   else
   {
     top--;
     return (&stack[top+1]);
   }
   return;
}

void peep()
{
   int val;
   if(top==-1)
   {
	 printf("\nStack Empty!!\n");
   }
   else
   {
     printf("Book at top=\n");
	 show(stack[top]);
   }
}


void push(book b)
{
   if(top==size-1)
   printf("\nStack Full!!\n");
   else
   {
   top++;
   stack[top]=b;
   }
}

void display()
{
   int i;
   if(top==-1)
   {
     printf("\nStack Empty!!\n");
   }
   else
   { 
     printf("\nStack elements are:\n");
     for(i=top;i>=0;i--)
     {
	   show(stack[i]);
     }
   }
}

