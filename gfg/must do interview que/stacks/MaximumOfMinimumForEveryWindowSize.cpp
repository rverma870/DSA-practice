#include<bits/stdc++.h>
using namespace std;

vector<int> NSR(int arr[], int n)//nearest smallet to right
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

vector<int> NSL(int arr[] , int n)//nearest smallet to left
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
vector <int> maxOfMin(int arr[], int n)
{
  vector<int>ans(n+1,0);
  vector<int>left=NSL(arr,n);
  vector<int>right=NSR(arr,n);
  for(int i=0;i<n;i++)
  {
    if(arr[i] > ans[right[i]-left[i]-1] )
    ans[right[i]-left[i]-1]=arr[i];
  }
  for(int i=n-1; i>=1; i--)
    ans[i] = max(ans[i], ans[i+1]);
  ans.erase(ans.begin());  
  return ans;
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  vector<int>ans;
  ans=maxOfMin(arr,n);
  for(auto e:ans)
    cout<<e<<" ";
}
