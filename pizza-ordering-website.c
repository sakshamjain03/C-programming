#include<stdio.h>
#include<stdlib.h>
struct Pizza
{
    int ID,qty;
    char name[20];
    char address[30];
};
struct Pizza p[3];
int rear=-1;
int front=-1;
int ID=1;
int is_empty()
 {
     if(rear==front)
     {
         return 1;
     }
     else
     {
         return 0;
     }
 }
 int is_full()
 { 
     if(rear==2)
     {
         return 1;
     }
     else
     {
         return 0;
     }
 }
 void place_order()
 {
     if(is_full()==0)
     {
         rear++;
         p[rear].ID=ID++;
         printf("\nEnter name:");
         scanf("%s" ,p[rear].name);
         printf("\nEnter address:");
         scanf("%s" ,p[rear].address);
         printf("\nEnter quantity:");
         scanf("%d" ,&p[rear].qty);
     }
      else
      {
          printf("\nOrder is full!!");
      }
 }
 void dispatch_order()
 {
     if(is_empty()==0)
     {
         front++;
         printf("\nDispatched order is:");
         printf("\nID: &d",p[front].ID);
         printf("\nNAME: %s",p[front].name);
         printf("\nADDRESS: %s",p[front].address);
         printf("\nQUANTITY: %d",p[front].qty);
     }
     else
     {
         printf("\nNo more orders to be dispatched!!");
     }
 }
 void display()
 {
     printf("\nThe pending orders are: ");
     for(int i=front+1;i<=rear;i++)
     {
         printf("\nID: %d",p[i].ID);
         printf("\nNAME: %s",p[i].name);
         printf("\nADDRESS: %s",p[i].address);
         printf("\nQUANTITY: %d",p[i].qty);
     }
 }
 int main()
 {
     int c;
     do
     {
         printf(".................MENU...........");
         printf("\n1.Place Order 2.Dispatch order 3.Display pending orders 4.EXIT");
         printf("\nEnter choice");
         scanf("%d",&c);
         switch(c)
         {
            case 1: place_order();
                    break;
            case 2: dispatch_order();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
                    break;
            default: return EXIT_SUCCESS;
         }
     }
      while(c<4);
     return 0;
 }

