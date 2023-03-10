#include<stdio.h>
#include<stdlib.h>
typedef struct BSTnode
{
    int data;
    struct BSTnode *left,*right;
}BSTnode;

BSTnode *find(BSTnode *,int);
BSTnode *insert(BSTnode *,int);
BSTnode *create();
void inorder(BSTnode *T);
void preorder(BSTnode *T);
void postorder(BSTnode *T);

int main()
{
    BSTnode *root=NULL,*p;
    int x,op;
    do
     {
         printf("\n1)Create\n2)Search\n3)Insert\n4)Preorder");
         printf("\n5)Inorder\n6)Postorder\n7)Quit");
         printf("\nEnter Your Choice :");
         scanf("%d",&op);
         switch(op)
           {
               case 1: root=create();break;
               case 2: printf("\nEnter the key to be searched:");
                   scanf("%d",&x);
                   p=find(root,x);
                   if(p==NULL)
                     printf("\n*****Not Found*****");
                   else
                     printf("\n****Found******");
                    break;
                case 3: printf("\nEnter a Data to be Inserted :");
                   scanf("%d",&x);
                   root=insert(root,x);
                   break;
                case 4: preorder(root);break;
                case 5: inorder(root);break;
                case 6: postorder(root);break;
               }
     }while(op!=7);
     return(0);
}  

   void inorder(BSTnode *T)
   {
       if(T!=NULL)
         {
             inorder(T->left);
             printf("%d\t",T->data);
             inorder(T->right);
         }
   }
   
     void preorder(BSTnode *T)
     { if(T!=NULL)
        { printf("%d\t",T->data);
          preorder(T->left);
          preorder(T->right);
        }
     }
     void postorder(BSTnode *T)
     { if(T!=NULL)
        { 
            postorder(T->left);
            postorder(T->right);
            printf("%d\t",T->data);
        }
     }
     
      BSTnode *find(BSTnode *root,int x)
      {
          while(root!=NULL)
          {
              if(x==root->data)
                return(root);
              if(x>root->data)
                root=root->right;
             else
             root=root->left;
          }
          return(NULL);
      }
      
       BSTnode *insert(BSTnode *T,int x)
       {
           BSTnode *p,*q,*r;
           r=(BSTnode*)malloc(sizeof(BSTnode));
           r->data=x;
           r->left=NULL;
           r->right=NULL;
           if(T==NULL)
             return(r);
             
        p=T;
        while(p!=NULL)
        {
            q=p;
            if(x>p->data)
              p=p->right;
            else
            if(x<p->data)
              p=p->left;
            else
             {
                 printf("\nDuplicate Entry :");
                 return(T);
            }
        }
        if(x>q->data)
           q->right=r;
        else
           q->left=r;
         return(T);  
}

    BSTnode *create()
    {
        int n,x,i;
        BSTnode *root;
        root=NULL;
        printf("\nEnter no. of nodes :");
        scanf("%d",&n);
        printf("\nEnter tree values :");
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            root=insert(root,x);
        }
        return(root);
 }

