
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100

int front = 0;
int back = 0;

typedef struct {
    char Item_name[50];
    int price, quantity, Item_Id;
} Item;

Item queue[SIZE];
int sum = 0;

void Insert() {
    if(back == 49) {
        printf("Queue is FUll!!!\n");
    }
    else {
        printf("-------------- Enter Items Details --------------\n");
        printf("Item_Id : ");
        scanf("%d", &queue[back].Item_Id);
        gets(queue[back].Item_name);
        printf("Item_name : ");
        gets(queue[back].Item_name);
        printf("price: ");
        scanf("%d", &queue[back].price);
        printf("quantity: ");
        scanf("%d", &queue[back].quantity);
        printf("\n");
        sum += queue[back].price*queue[back].quantity;
        back++;
    }
}

void Remove() {
    if(front == back) {
        printf("\nQueue is Empty!!!\n\n");
    }
    else {
        front++;
        printf("Item Removed.\n");
        if(front == back) {
            printf("\n\nALL ITEMS REMOVED. TOTAL BILL IS :-\n\n");
	printf("%d",sum);
            getch();
        }
    }
}
void Peek() {
    if(front == back) {
        printf("\nQueue is Empty!!!\n\n");
    }
    else {
        printf("Item_name of item at front is : %d\n\n", queue[front].Item_Id);
    }
}
void Display() {
    if(front == back) {
        printf("\nQueue is Empty!!!\n\n");
    }
    else {
        int i = 0;
        printf("             *****  INVENTORY ***** \n");
    printf("---------------------------------------------------------\n");
    printf("S.N.|    NAME           |   Id   |  QUANTITY |  PRICE\n");
    printf("---------------------------------------------------------\n");
        for(i = front; i < back; i++) {
          printf("%d        %-15s     %-d       %-5d      %-5d  \n", i + 1,queue[i].Item_name,queue[i].Item_Id,queue[i].quantity,queue[i].price);
    printf("---------------------------------------------------------\n");   
        }
        printf("\n\n");
    }
}

int main() {
    int o;
    while(1) {
        printf("Options\n1.Insert\n2.Remove\n3.Peek\n4.Display\n5.Exit\n");
        printf("\nEnter your Option : ");
        scanf("%d", &o);
        switch(o) {
        case 1:
            Insert();
            break;
        case 2:
            Remove();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Display();
            break;
        case 5:exit(0);
		default:printf("Enter valid choice!!\n");
		}
    }
    getch();
}
 

