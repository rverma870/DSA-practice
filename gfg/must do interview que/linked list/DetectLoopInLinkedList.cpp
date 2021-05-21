bool detectLoop(Node* head)
{
    unordered_set<Node *>st;
    Node * it = head;
    while(it!=NULL)
    {
        if(st.find(it)!=st.end())
            return true;
        st.insert(it);
        it=it->next;
    }
    return false;
}
