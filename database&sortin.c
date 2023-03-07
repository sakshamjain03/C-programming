#include <stdio.h>
void insertion_sort(int[],int);
void selection_sort(int a[],int n);
void bubble_sort(int a[],int n);
int main() 
{
    int a[50],n,i,op;
    do
    {
        printf("\n1)Insertion\n2)Selection\n3)Bubble\n4)Quit");
        printf("\nEnter your choice :");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("Enter no of elements :");
            scanf("%d",&n);
            printf("\nEnter array elements :");
            for(i=0;i<n;i++)
            scanf("%d",&a[i]);
            insertion_sort(a,n);
            break;
            
            case 2: printf("\nEnter no of elements :");
            scanf("%d",&n);
            printf("\nEnter array elements :");
            for(i=0;i<n;i++)
            scanf("%d",&a[i]);
            selection_sort(a,n);
            break;
            
            case 3:  printf("\nEnter no of elements :");
            scanf("%d",&n);
            printf("\nEnter array elements :");
            for(i=0;i<n;i++)
            scanf("%d",&a[i]);
            bubble_sort(a,n);
            break;
            }
        } while(op!=4);
}
    void insertion_sort(int a[],int n)
    {
        int i,j,temp,k;
        printf("\nUnsorted Data :");
        for(k=0;k<n;k++)
        printf("%5d",a[k]);
        for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0 && a[j]>temp;j--)
        a[j+1]=a[j];
        a[j+1]=temp;
        printf("\n(After pass %d)",i);
        for(k=0;k<n;k++)
         printf("%5d",a[k]);
    }    
}
 void selection_sort(int a[],int n)
 {
     int i,j,temp,k;
     printf("\nUnsorted Data :");
     for(k=0;k<n;k++)
        printf("%5d",a[k]);
      for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        if (a[j]<a[k])
        k=j;
        temp=a[i];
        a[i]=a[k];
        a[k]=temp;
        printf("\n(After pass %d)",i+1);
        for(k=0;k<n;k++)
         printf("%5d",a[k]);
    }
 }
     void bubble_sort(int a[],int n)
     {
         int i,j,k,temp;
         printf("\nUnsorted Data :");
     for(k=0;k<n;k++)
        printf("%5d",a[k]);
      for(i=1;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        if (a[j]>a[j+1])
        {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        }
        printf("\n(After pass %d)",i);
        for(k=0;k<n;k++)
         printf("%5d",a[k]);
    }
}
