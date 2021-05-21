#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
  vector<long long>ans;
  stack<long long>stk;

  for(int i=n-1;i>=0;i--)
  {
    if(stk.empty())
      ans.push_back(-1);
    else if(stk.top()>arr[i])
      ans.push_back(stk.top());
    else
    {
      while(stk.top()<=arr[i])
      {
          stk.pop();
          if(stk.empty())
           break;
      }
      if(stk.empty())
        ans.push_back(-1);
      else
        ans.push_back(stk.top());
    }
    stk.push(arr[i]);
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

int main()
{
  int n;
  cin>>n;
  vector<long long>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  vector<long long>ans;
  ans=nextLargerElement(arr,n);
  for(auto e:ans)
  cout<<e<<" ";
}
