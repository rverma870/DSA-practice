#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& M, int n)
{
  stack<int>stk;
  for(int i=0;i<n;i++)
    stk.push(i);
  while(stk.size()>1)
  {
    int x=stk.top();
    stk.pop();
    int y=stk.top();
    stk.pop();
    if(M[x][y]==1)
      stk.push(y);
    else
      stk.push(x);
  }
  for(int j=0;j<n;j++)
  {
    if(M[stk.top()][j]!=0)
      return -1;
  }
  for(int i=0;i<n;i++)
  {
    if(M[i][stk.top()]==0 && i!=stk.top())
      return -1;
  }
  return stk.top();
}
int main()
{
  int n;
  cin>>n;
  vector<vector<int>>M(n);
  for(int i=0;i<n;i++)
  {
    vector<int>temp(n);
    for(int j=0;j<n;j++)
    {
      cin>>temp[j];
    }
      M[i]=temp;
  }
  cout<<celebrity(M,n);
}
