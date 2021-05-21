#include<bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
  stack<char>stk;
  for(int i=0;i<x.length();i++)
  {
    if(x[i]=='(' || x[i]=='[' || x[i]=='{')
      stk.push(x[i]);
    else
    {
      if(stk.empty())
        return false;
      if((stk.top()=='(' && x[i]==')') || (stk.top()=='[' && x[i]==']') || (stk.top()=='{' && x[i]=='}'))
        stk.pop();
      else
        return false;
    }
  }
  if(stk.empty())
    return true;
  else
    return false;
}

int main()
{
  string x;
  cin>>x;
  cout<<ispar(x);
}
