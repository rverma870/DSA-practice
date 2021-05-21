Node *copyList(Node *head)
{
    //creating dummy list
    Node * it = head, * real_link=NULL ;//creating_node
    while(it!=NULL)
    {
       real_link=it->next;
       it->next=new Node(it->data);
       it->next->next=real_link;
       it=it->next->next;
    }
    Node * new_head=head->next;
    //taking care of arb pointer
    Node * front=head->next->next ,* it_newlist=new_head;
    it=head;
    while(it!=NULL)
    {
        if(it->arb!=NULL)
        it->next->arb=it->arb->next;
        else
        it->next->arb=NULL;
        it=it->next->next;
    }
    it=head;
    while(it!=NULL)
    {
        it->next=front;
        it=front;
        if(it!=NULL)
        {
            it_newlist->next=it->next;
            it_newlist=it->next;
            front=it->next->next;
        }
        else
            it_newlist->next=NULL;

    }
    return new_head;
}
