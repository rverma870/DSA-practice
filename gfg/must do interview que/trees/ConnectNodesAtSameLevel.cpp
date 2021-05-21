void connect(Node *root)
{
    vector<pair<Node*,int>>v;
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        if(q.front().first->left!=NULL)
        q.push(make_pair(q.front().first->left , q.front().second+1));
        if(q.front().first->right!=NULL)
        q.push(make_pair(q.front().first->right , q.front().second+1));
        v.push_back(q.front());
        q.pop();
    }
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        if(i!=n-1 && v[i].second==v[i+1].second)
        {
            v[i].first->nextRight=v[i+1].first;
        }
        else
        {
            v[i].first->nextRight=NULL;
        }
    }
}
