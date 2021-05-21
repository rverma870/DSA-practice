#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,x;
  cin>>n>>x;
  int price[n],page[n];
  for(int i=0;i<n;i++)
    cin>>price[i];
  for(int i=0;i<n;i++)
    cin>>page[i];
  int t[n+1][x+1];
  for(int i=0;i<n+1;i++)
  t[i][0]=0;
  for(int i=0;i<x+1;i++)
  t[0][i]=0;
  for(int i=1;i<n+1;i++)
  {
    for(int j=1;j<x+1;j++)
    {
      if(j>=price[i-1])
      {
        t[i][j]=max(page[i-1]+t[i-1][j-price[i-1]],t[i-1][j]);
      }
      else
      {
        t[i][j]=t[i-1][j];
      }
    }
  }
  cout<<t[n][x];  
}
