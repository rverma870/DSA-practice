#include<bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> arr , int n)//nearest smallet to left
{
  vector<int>ans;
  stack<pair<int,int>>stk;

  for(int i=0;i<n;i++)
  {
    if(stk.empty())
      ans.push_back(-1);
    else if(stk.top().first<arr[i])
      ans.push_back(stk.top().second);
    else
    {
      while(stk.top().first>=arr[i])
      {
          stk.pop();
          if(stk.empty())
           break;
      }
      if(stk.empty())
        ans.push_back(-1);
      else
        ans.push_back(stk.top().second);
    }
    stk.push(make_pair(arr[i],i));
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  for(auto e:NSL(arr,n))
  cout<<e<<" ";
}
