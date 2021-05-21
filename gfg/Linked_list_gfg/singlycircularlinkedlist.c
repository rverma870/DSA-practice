#include<stdio.h>
#include<stdlib.h>

 typedef struct node
 {
   int data;
   struct node *next;
 }node;
 int main()
{
   int x,choice=1;
  node * newnode,* head=0 ,* tail,* p;
  do
  {newnode=(node*)malloc(sizeof(node));
  printf("enter data:");
  scanf("%d",&x);
  newnode->data=x;
  newnode->next=0;
  if(head==0)
  {
    head=tail=newnode;
  }
  else
  {
    tail->next=newnode;
    tail=newnode;
    tail->next=head;
  }
  choice=0;
  printf("do you wanna continue:");
  scanf("%d",&choice);
  }while(choice==1);

  p=head;

 do
 {
   printf("\nlinkedlist->%d ",p->data);
   p=p->next;
 }while(p!=tail->next);

return 0;
}
