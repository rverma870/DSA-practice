#include<bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
  priority_queue<long long, vector<long long>, greater<long long>>q;
  for(long long i=0;i<n;i++)
    q.push(arr[i]);
  long long ans=0;
  while(q.size()>1)
  {
    long long x,y;
    x=q.top();
    q.pop();
    y=q.top();
    q.pop();
    ans+=x+y;
    q.push(x+y);
  }
  return ans;    
}

int main()
{
  long long n;
  cin>>n;
  long long arr[n];
  for(long long i=0;i<n;i++)
    cin>>arr[i];
  cout<<minCost(arr,n);
}
