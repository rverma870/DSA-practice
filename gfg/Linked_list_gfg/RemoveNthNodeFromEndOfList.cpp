#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
  ListNode * start=new ListNode();
  start->next=head;
  ListNode * fast =start;
  ListNode * slow =start;
  int count=0;
  while(count<n)
  {
    fast=fast->next;
    count++;
  }
  if(fast->next==NULL)
  {
      ListNode * temp =head;
      head=head->next;
      delete temp;
      return head;
  }
  while(fast->next!=NULL)
  {
    fast=fast->next;
    slow=slow->next;
  }
  ListNode * to_del=slow->next;
  slow->next=slow->next->next;
   delete to_del;
  return head;
}
void print_linked_list(ListNode * head)
{
  ListNode * temp=head;
  while(temp!=NULL)
  {
    cout<<temp->val<<" ";
    temp=temp->next;
  }
}
int main()
{
  int n,x;
  cin>>n>>x;
  ListNode * head=NULL, * tail=NULL;
  int first_val,l;
  cin>>first_val;

  head=new ListNode(first_val);
  tail=head;

  for(int i=0;i<n-1;i++)
  {
    cin>>l;
    tail->next=new ListNode(l);
    tail=tail->next;
  }
  print_linked_list(head);
  cout<<endl;
  head=removeNthFromEnd(head,x);
  print_linked_list(head);
}
