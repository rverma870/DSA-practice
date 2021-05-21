Node* sortedMerge(Node* head1, Node* head2)
{
    Node * temp = new Node(-1);
    Node * res =temp;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data <=head2->data)
        {
            temp->bottom=head1;
            temp=temp->bottom;
            head1=head1->bottom;
        }
        else
        {
            temp->bottom=head2;
            temp=temp->bottom;
            head2=head2->bottom;
        }
    }
    if(head1!=NULL)
        temp->bottom=head1;
    else
        temp->bottom=head2;
    return res->bottom;
}
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL)
    return root;

   root->next=flatten(root->next);

   root=sortedMerge(root,root->next);
   return root;
}
