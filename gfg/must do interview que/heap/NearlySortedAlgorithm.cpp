#include<bits/stdc++.h>
using namespace std;

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<n;i++)
    {
      if(q.size()<=k)
        q.push(arr[i]);
      if(q.size()>k)
      {
        cout<<q.top()<<" ";
        q.pop();
      }
    }
    while(!q.empty())
    {
      cout<<q.top()<<" ";
      q.pop();
    }
    cout<<endl;
  }
}
