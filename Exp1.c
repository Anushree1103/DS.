#include<stdio.h>
  void demo_2d();
  void swapping();
  void factadd();
  int fact(int x);
  
int main()
{
   int choice;
   printf("MENU:\n1.Fcatorial Add\n2.2D Array Demo\n3.Swapping\n4.Exit\nEnter Your Choice: ");
   scanf("%d",&choice);
   switch(choice)
   {
     case 1: factadd();
             break;
     case 2: demo_2d();
             break;
     case 3: swapping();
             break;
     case 4:
             break;
     default: printf("WRONG CHOICE");
    }
return 0;
}

void factadd()
{
    int a[100];
    int i,n,sum=0,f=0;
    printf("Enter value of n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
     printf("Enter the value :");
     scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {   
     f=fact(a[i]);
	 sum=sum+f;
    }
    printf("Sum of all factorial is ",sum);
	
	
}

int fact(int n)
{
    int i,fact=1;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    return fact;
}

void demo_2d()
{
    int a[100][100];
	int i,j,sum=0;
	int m,n;
	printf("Enter the size m and n:");
	scanf("%d%d",&m,&n);
    printf("Enter elements of matrix:\n");
	for(i=0;i<m;i++)
	{
	   for(j=0;j<n;j++)
	   {
	       scanf("%d",&a[i][j]);
		   sum=sum+a[i][j];
	   }  
	}	  
	printf("Sum of matrix elements= %d ",sum);  
	

}


void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void swapping()
{
    int a[100];
    int n;
    int i;
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Enter the numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array contents:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    for(i=0;i<(n/2);i++)
    {
        swap(&a[i],&a[n-i-1]);
    }
    printf("\nArray contents after swapping:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

}

