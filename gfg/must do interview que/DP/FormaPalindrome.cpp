#include<bits/stdc++.h>
using namespace std;
int findMinInsertions(string S)
{
  string rev = S;
  reverse(rev.begin(),rev.end());
  int x=S.length();
  int y=x;
  int t[x+1][y+1];
  for(int i=0;i<=x;i++)
      t[i][0]=0;
  for(int j=0;j<=y;j++)
      t[0][j]=0;

  for(int i=1;i<=x;i++)
  {
    for(int j=1;j<=y;j++)
    {
      if(S[i-1]==rev[j-1])
      {
          t[i][j]=1+t[i-1][j-1];
      }
      else
      {
          t[i][j]=max(t[i-1][j],t[i][j-1]);
      }
    }
  }
  return x-t[x][y];
}

int main()
{
  string S;
  cin>>S;
  cout<<findMinInsertions(S)<<endl;

}
