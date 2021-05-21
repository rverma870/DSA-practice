#include<bits/stdc++.h>
using namespace std;

string Reduced_String(int k,string s)
{
  string ans;
  stack<pair<char,int>>stk;
  int count=1;
  for(int i=0;i<s.length();i++)
  {
    if(stk.empty() || stk.top().first!=s[i])
    {
      stk.push(make_pair(s[i],1));
    }
    else
    {
      count=stk.top().second+1;
      stk.push(make_pair(s[i],count));
    }

    if(stk.top().second==k)
    {
      int t=k;
      while(t--)
        stk.pop();
    }
  }
  while(!stk.empty())
  {
    ans.push_back(stk.top().first);
    stk.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  int k;
  cin>>k;
  string s;
  cin>>s;
  cout<<Reduced_String(k,s);
}
