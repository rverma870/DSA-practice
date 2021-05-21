#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node * next;
  node(int x)
  {
    data=x;
    next=NULL;
  }
};

pair<node*,node*>reverseList(struct node *head,int k)
{
  node * new_head=NULL,*tail=head;
  int count=0;
  while(head!=NULL &&count<k)
  {
    node * next=head->next;
    head->next=new_head;
    new_head=head;
    head=next;
    count++;
  }
  tail->next=head;
  return make_pair(new_head,tail);
}

void print_linked_list(node * head)
{
  node * temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
node *reverse (node *head, int k)
{
  int count=0;
  node * it =head;
  while(count!=k && it!=NULL )
  {
    it=it->next;
    count++;
  }
  node * new_head=head, * cur_tail=NULL;
  pair<node*,node*>p;
  if(count==k)
  {
    p=reverseList(head,k);
    new_head=p.first;
    cur_tail=p.second;
  }
  count=0;
  node * tmp_it=it;
  while(it!=NULL && count<k)
  {
    it=it->next;
    count++;
    if(count==k)
    {
      count=0;
      p=reverseList(tmp_it,k);
      cur_tail->next=p.first;
      cur_tail=p.second;
      tmp_it=it;
    }
  }
  if(count!=k && tmp_it!=NULL)
  {
     p=reverseList(tmp_it,k);
     cur_tail->next=p.first;
     cur_tail=p.second;
     tmp_it=it;
  }
  return new_head;
}

int main()
{
  int n;
  cin>>n;
  node * head=NULL, * tail=NULL;
  int first_data,l;
  cin>>first_data;

  head=new node(first_data);
  tail=head;

  for(int i=0;i<n-1;i++)
  {
    cin>>l;
    tail->next=new node(l);
    tail=tail->next;
  }
  int k;
  cin>>k;

  print_linked_list(reverse(head,k));
}
