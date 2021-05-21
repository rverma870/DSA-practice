#include<bits/stdc++.h>
using namespace std;

vector <int> calculateSpan(int price[], int n)
{
  stack<pair<int,int>>stk;//value,index
  vector<int>ans;
  for(int i=0;i<n;i++)
  {
    if(stk.empty())
      ans.push_back(1);
    else if(stk.top().first>price[i])
      ans.push_back(1);
    else
    {
      while(stk.top().first<=price[i])
      {
        stk.pop();
        if(stk.empty())
          break;
      }
      if(stk.empty())
        ans.push_back(i+1);
      else
        ans.push_back(i-stk.top().second);
    }
    stk.push(make_pair(price[i],i));
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  vector<int>ans;
  ans=calculateSpan(a,n);
  for(auto e:ans)
    cout<<e<<" ";
}
