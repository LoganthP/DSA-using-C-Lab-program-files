#include <stdio.h>
#include <ctype.h>
#include <math.h>
char stack[100];
int top = -1;

void push(char x)
{
 stack[++top] = x;
}

char pop()
{
 if(top == -1)
  return -1;
 else
 return stack[top--];
}

int priority(char x)
{
 if(x == '(')
  return 0;
 if(x == '+' || x == '-')
  return 1;
 if(x == '*' || x == '/' || x=='%')
  return 2;
 if(x=='^')
  return 3;
 return 0;
}

void main()
{
 char exp[20];
 char *e, x;
 printf("Enter the expression : ");
 scanf("%s", exp);
 printf("\n");
 e = exp;
 while (*e != '\0')
 {
  if(isalnum(*e))
    printf("%c", *e);
  else if (*e == '(')
    push(*e);
  else if(*e == ')')
  {
   while ((x = pop()) != '(')
   printf("%c", x);
  }
  else
  {
   while(priority(stack[top]) >= priority(*e))
   printf("%c", pop());
   push(*e);
  }
  e++;
 }
 while(top != -1)
 {
   printf("%c", pop());
 }

 char postfix[20];
 char *p;
 int n1,n2,n3,num;
 printf("\n Enter the result to calculate :: ");
 scanf("%s",postfix);
 p = postfix;
 while(*p != '\0')
 {
  if(isdigit(*p))
  {
   num = *p - 48;
   push(num);
  }
  else
  {
   n1 = pop();
   n2 = pop();
  switch(*p)
  {
   case '+':
   {
    n3 = n2 + n1;
    break;
   }
   
   case '-':
   {
    n3 = n2 - n1;
    break;
   }
   
   case '*':
   {
    n3 = n2 * n1;
    break;
   }
   
   case '/':
   {
    n3 = n2 / n1;
    break;
   }
   
   case '^':
   {
    n3 = pow(n2,n1);
    break;
   }
   
   case '%':
   {
    n3 = n2%n1;
    break;
   }
  }
  push(n3);
  }
  p++;
 }
 printf("\n The result of the converted postfix = %d",pop());
}