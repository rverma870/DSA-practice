#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}
};

Node* Merge(Node* head1, Node* head2)
{
  Node * temp = new Node(-1);
  Node * res =temp;
  while(head1!=NULL && head2!=NULL)
  {
      if(head1->data <=head2->data)
      {
          temp->next=head1;
          temp=temp->next;
          head1=head1->next;
      }
      else
      {
          temp->next=head2;
          temp=temp->next;
          head2=head2->next;
      }
  }
  if(head1!=NULL)
      temp->next=head1;
  else
      temp->next=head2;
  return res->next;
}

Node * mergeKLists(Node *arr[], int K)
{
    int i=0,last=K-1,j;
    while(i<last)
    {
        i=0;
        j=last;
        while(i<j)
        {
            arr[i]=Merge(arr[i],arr[j]);
            i++;
            j--;
        }
        last=j;
        i=0;
    }
    return arr[0];
}

int main()
{

}
