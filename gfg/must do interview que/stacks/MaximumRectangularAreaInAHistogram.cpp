#include<bits/stdc++.h>
using namespace std;

vector<long long> NSR(long long arr[], int n)//nearest smallet to right
{
  vector<long long>ans;
  stack<pair<long long,long long>>stk;

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

vector<long long> NSL(long long arr[] , int n)//nearest smallet to left
{
  vector<long long>ans;
  stack<pair<long long,long long>>stk;

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
long long getMaxArea(long long arr[], int n)
{
  vector<long long>left,right;
  left=NSL(arr,n);
  right=NSR(arr,n);
  long long ans=0;
  for(int i=0;i<n;i++)
    ans=max(ans,((right[i]-left[i]-1)*arr[i]));
  return ans;
}
int main()
{
  int n;
  cin>>n;
  long long arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<getMaxArea(arr,n);
}
