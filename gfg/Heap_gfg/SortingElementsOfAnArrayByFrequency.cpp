#include <bits/stdc++.h>
using namespace std;
class compare
{
    public:
    bool operator()(pair<int,int>a , pair<int,int>b)
    {
        if(a.first!=b.first)
            return a.first<b.first;
        else
            return a.second>b.second;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[arr[i]]+=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>q;
        for(auto e:mp)
            q.push(make_pair(e.second,e.first));
        while(!q.empty())
        {
            for(int i=0;i<q.top().first;i++)
                cout<<q.top().second<<" ";
            q.pop();
        }
        cout<<endl;
    }
}
