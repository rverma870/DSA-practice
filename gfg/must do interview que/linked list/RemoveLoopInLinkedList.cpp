#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node * next;
  Node(int x)
  {
    data=x;
    next=NULL;
  }
};

void print_linked_list(Node * head)
{
  Node * temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
void removeLoop(Node* head)
{
   Node * fast=head;
   Node * slow=head;
   Node * entry=head;

   while(fast->next!=NULL && fast->next->next!=NULL)
   {
       fast=fast->next->next;
       slow=slow->next;
       if(fast==slow)
       {
           if(slow==head)
           {
              Node* it=head;
              while(it->next!=head)
                  it=it->next;
              it->next=NULL;
              break;
           }
           else
           {
              while(slow->next!=entry->next)
              {
                 slow=slow->next;
                 entry=entry->next;
              }
             slow->next=NULL;
             break;
           }
       }
   }
}
int main()
{
  int n;
  cin>>n;
  Node * head=NULL, * tail=NULL;
  int first_data,l;
  cin>>first_data;

  head=new Node(first_data);
  tail=head;

  for(int i=0;i<n-1;i++)
  {
    cin>>l;
    tail->next=new Node(l);
    tail=tail->next;
  }
  print_linked_list(head);
}
