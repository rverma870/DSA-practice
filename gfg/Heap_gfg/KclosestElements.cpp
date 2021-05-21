#include<bits/stdc++.h>
using namespace std;

vector<int> printKClosest(vector<int> arr, int n, int k, int x)
{
    priority_queue<pair<int,int>>q;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(q.size()<=k)
            q.push(make_pair(abs(arr[i]-x),arr[i]));
        if(q.size()>k)
        {
            q.pop();
        }
    }
    while(!q.empty())
    {
      ans.push_back(q.top().second);
      q.pop();
    }
    return ans;
}

int main()
{
  int k,n,x;
  cin>>n>>k>>x;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  for(auto e: printKClosest(arr,n,k,x))
    cout<<e<<" ";
}
