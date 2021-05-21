int intersectPoint(Node* head1, Node* head2)
{
  map<Node *,int>mp;
  Node * it1=head1;
  mp.insert(make_pair(it1,head1->data));
  while(it1->next!=NULL)
  {
     mp.insert(make_pair(it1->next,it1->next->data));
     it1=it1->next;
  }
  Node * it2= head2;
  while(it2!=NULL)
  {
      if(mp.find(it2)!=mp.end())
        return mp[it2];
      it2=it2->next;
  }
  return -1;
}
