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

int getMaxArea(vector<int>arr, int n)
{
  vector<int>left,right;
  left=NSL(arr,n);
  right=NSR(arr,n);
  int ans=0;
  for(int i=0;i<n;i++)
    ans=max(ans,((right[i]-left[i]-1)*arr[i]));
  return ans;
}

int maxArea(int arr[][1000], int n, int m)
{
  vector<int>temp;
  int ans=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(i==0)
        temp.push_back(arr[i][j]);
      else if(arr[i][j]==0)
        temp.push_back(0);
      else
      {
        temp.push_back(arr[i][j]+arr[i-1][j]);
        arr[i][j]+=arr[i-1][j];
      }  
    }
    int x=getMaxArea(temp,m);
    cout<<x<<endl;
    ans=max(ans,x);
    temp.clear();
  }
  return ans;
}

int main()
{
  int n,m;
  cin>>n>>m;
  int arr[n][1000];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    cin>>arr[i][j];
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    cout<<arr[i][j]<<" ";
    cout<<endl;
  }
  cout<<maxArea(arr,n,m);
}
