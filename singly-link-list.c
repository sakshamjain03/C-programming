#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
    
}node;

node *create();
void print(node *head);


node *create(){
    
    node *head = NULL;
    node *p;
    int x, i;
    
    printf("Enter number of data to add: ");
    scanf("%d", &x);
    //printf("%d", x);
    for (i = 0; i<x; i++){
        printf("Enter data for node %d :", i+1);
        
        if (head == NULL){
            p = head = (node* )malloc(sizeof(node));
        }
        
        else{
            p->link = (node* )malloc(sizeof(node));
            p = p->link;
            
        }
        
        p->link = NULL;
        scanf("%d", &(p->data));
    
    }
    
    return(head);
    
}

void print(node *head){
    
    node *p;
    printf("\n\n");
    int i = 1;
    for (p = head; p!=NULL;p = p->link){

        printf("Data %d is: %d\n",i, p->data);
        i+=1;
    }
    printf("--------------------------------------\n");
    
}


node *findlast(node *head){

    node *temp = head;

    for (temp = head; temp->link!=NULL; temp=temp->link){

    }
    return temp;


}

node *inBetween(node *head, int data_mid, int after_serial){

    //int data_mid, after_serial;
    node *before=head;
    node *after=head;
    node *ptr;
    //data_mid = 97;
    //after_serial = 3;

    ptr = (node*)malloc(sizeof(node));
    ptr->data = data_mid;

    for (int j=0; j<after_serial-1; j++){

        after = after->link;
         

    }//after is the node jyachanantar new add karaychay
     //after chya link madhe ptr cha address      (1)
     //after chi link == ptr chi link             (2)

    ptr->link = after->link;   //   (2)
    after->link = ptr;         //   (1)
     
    
    return head;

}


node *atStart(node *head, int data_start){

    node *ptr;
    //int data_start;

    ptr = (node*)malloc(sizeof(node));                  //created a node to be added
    ptr->data =  data_start;
    ptr->link = head;

    head = ptr;                                         //head address == new node

    return head;

}


node *atEnd(node *head, int data_end){

    node *ptr;
    //int data_end=40;

    ptr = (node*)malloc(sizeof(node));
    ptr->data = data_end;
    ptr->link = NULL;

    node *last = findlast(head);
    last->link = ptr;

    return head;
}


node *deleteEnd(node *head){

    node *temp;

    for(temp=head; temp->link->link != NULL; temp=temp->link){

    }
    free(temp->link->link);
    temp->link = NULL;

    return head;

}

node *deleteStart(node *head){

    node *temp;
    temp = head->link;
    free(head);

    return temp;

}

node *deleteMidData(node *head, int del_data){

    node *temp;
    node *delink;       //pointer to store link of the node that is next to the node to be deleted
    //int del_data = 5;      //data to be deleted
    for(temp = head; temp->link->data != del_data; temp=temp->link){

    }
    delink = temp->link->link;
    free(temp->link);
    temp->link = delink;

    return head;

    


}


int main()
{
    int op,choice, data_toadd, after_serial, delchoice, del_data;
    node *head = NULL;
    node *first, *second, *third, *fourth, *fifth;
 
 
    do{
    printf("Select Operation: \n1)create\n2)Insert\n3)Delete\n4)Print\n5)Exit\nYour choice: ");
    scanf("%d", &op);
    
    switch(op){
        case 1: head = create();
                //print(head);
                break;
        
        case 2: printf("Select:  (1)At start  (2)In between  (3)At end \nYour choice: ");
                scanf("%d", &choice);
                printf("Enter data to be added: ");
                scanf("%d", &data_toadd);
                switch(choice){
                    case 1: head = atStart(head, data_toadd);
                            print(head);
                            break;

                    case 2: printf("Data added after serial number: ");
                            scanf("%d", &after_serial);
                            head = inBetween(head, data_toadd, after_serial);
                            print(head);
                            break;

                    case 3: head = atEnd(head, data_toadd);
                            print(head);
                            break;
                }

                break;

        case 3: printf("Select: (1)At Start  (2)In Mid  (3)At end\nYour choice: ");
                scanf("%d", &delchoice);
                //printf("del choice is %d", delchoice);
                switch(delchoice){
                    case 1: head = deleteStart(head);
                            print(head);
                            break;

                    case 2: printf("Data to be deleted: ");
                            scanf("%d", &del_data);
                            head = deleteMidData(head,del_data);
                            print(head);
                            break;

                    case 3: head = deleteEnd(head);
                            print(head);
                            break;
                }

        case 4: print(head);
                break;

        case 5: printf("Programme ended!");
                break;

    }
    }while(op!=5);
    
     
    printf("\n");
    return 0;
}

