#include<bits/stdc++.h>
using namespace std;

vector<int> NSR(vector<int> arr, int n)//nearest smallet to right
{
  vector<int>ans;
  stack<pair<int,int>>stk;

  for(int i=n-1;i>=0;i--)
  {
    if(stk.empty())
      ans.push_back(n);
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
        ans.push_back(n);
      else
        ans.push_back(stk.top().second);
    }
    stk.push(make_pair(arr[i],i));
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  for(auto e:NSR(arr,n))
  cout<<e<<" ";
}
