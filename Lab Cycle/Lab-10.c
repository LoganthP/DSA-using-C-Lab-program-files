#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

typedef struct
{
 int id;
 char name[20];
}EMPLOYEE;
EMPLOYEE e[SIZE];

void initialize_table()
{
 for(int i=0; i<SIZE; i++)
 {
  e[i].id=0;
 }
}

void insert_table()
{
 int i, id, index, hvalue;
 char name[26];
 printf("Enter the employee id and name: ");
 scanf("%d %s", &id, name);
 hvalue= id % SIZE;
 for(i=0; i<SIZE; i++)
 {
  index=(hvalue+i) % SIZE;
  if(e[index].id==0)
  {
   e[index].id=id;
   strcpy(e[index].name,name);
   break;
  }
 }
 if(i==SIZE)
 {
  printf("Hash table full\n");
 }
}

void display_table()
{
 printf("H\t Id\t Name\n");
 for(int i=0; i<SIZE; i++)
 {
  printf("%d\t %d\t %s\n", i, e[i].id, e[i].name);
 }
}

void main()
{
 int ch=0, id;
 char name[26];
 initialize_table();
 while(ch<4)
 {
  printf("1:Insert\t 2:Display\t 3:Exit\n");
  printf("Enter the choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:insert_table( );
   break;
   case 2:display_table();
   break;
   case 3: exit(0);
   break;
   deafult: printf("Enter valid choice\n");
   break;
  }
 }
}