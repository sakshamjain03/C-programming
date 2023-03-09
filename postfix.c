#include<stdio.h>
#include<ctype.h>
#define MAX 50
typedef struct stack
{
	int data[MAX];
	int top;
}stack;
	void init(stack *);
	int empty (stack *);
	int full(stack *);
	int pop(stack *);
	void push(stack *,int);
	void evaluate(char postfix[]);
void main()
{
	char postfix[30];
	printf("\n ]Enter a postfix expression :");
	gets(postfix);
	evaluate(postfix);
}
void evaluate(char postfix[])
{ stack s;
	int op1,op2,val=0,i;
	init(&s);
for(i=0;postfix[i]!='\0';i++)
{
	if(isalpha(postfix[i]))
{
		printf("\nEnter the value of %c :",postfix[i]);
		scanf("%d",&val);
		push(&s,val);
}
else
{
	op2=pop(&s);
	op1=pop(&s);
switch(postfix[i])
{
	case '+':push (&s,op1+op2);break;
	case '-':push (&s,op1-op2);break;
	case '*':push (&s,op1*op2);break;
	case '/':push (&s,op1/op2);break;
	case '%':push (&s,op1%op2);break;
}
}
}
val=pop(&s);
printf("\nValue of the expression= %d",val);
}
void init(stack*s)
{
s->top=-1;
}
int empty(stack *s)
{
if(s->top==-1)
return(1);
return(0);
}
int full(stack*s)
{
if(s->top==MAX-1)
return(1);
return(0);
}
void push(stack*s,int x)
{
s->top=s->top+1;
s->data[s->top]=x;
}
int pop (stack *s)
{
int x;
x=s->data[s->top];
s->top=s->top-1;
return(x);
}
