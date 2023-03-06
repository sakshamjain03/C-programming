#include <stdio.h>
int binsearch (int a[], int i,int j, int key);
int linsearch (int a[],int n, int key);
int main ()
{
    int a[30],key,n, result, op,i;
do
{
printf("\nl) Linear Search\n2) Binary Search\n3) Quit");
printf("\nEnter Your Choice: ");
scanf("%d",&op);
switch (op)
{
case 1: printf("\n Enter No. of elements: ");
scanf("%d",&n);
printf("\n Enter a list of %d elements : ",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\n Enter the elements to be searched : ");
scanf("%d",&key);
result=linsearch (a,n,key);
if (result==-1)
printf("\n Not Found : ");
else
printf("\n Found at Location= %d",result+1);
break;
case 2: printf("\n Enter No. of elements : ");
scanf("%d",&n);
printf("\n Enter a sorted list of %d elements : ",n);
for(i=0;i<n;i++);
scanf("%d",&a[i]);
printf("\n Enter the elements to be searched : ");
scanf("%d",&key);
result=binsearch(a,0,n-1,key);
if(result==-1)
printf("\n Not Found : ");
else
printf("\n Found at Location = %d",result+1);
break;
}
} while(op!=3);
}
int binsearch (int a[],int i,int j,int key)
{
    int c;
    if (i>j)
    return(-1);
    c=(i + j)/2;
    if(key==a[c])
    return(c);
    if (key>a[c])
    return(binsearch(a,c+1,j,key));
    return(binsearch(a,i,c-1,key));
}
int linsearch(int a[],int n, int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        return(i);
    }
    return(-1); 
}
