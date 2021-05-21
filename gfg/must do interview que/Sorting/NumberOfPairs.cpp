#include<bits/stdc++.h>
using namespace std;

long long countPairs(int X[], int Y[], int M, int N)
{
  long long ans=0,zeros=0,ones=0,twos=0,threes=0,four=0;
  for(int i=0;i<N;i++)
  {
    if(Y[i]==0)
    zeros++;
    if(Y[i]==1)
    ones++;
    if(Y[i]==2)
    twos++;
    if(Y[i]==3)
    threes++;
    if(Y[i]==4)
    four++;
  }
  sort(Y,Y+N);
  for(int i=0;i<M;i++)
  {
    if(X[i]==0)
    continue;
    else if(X[i]==1)
      ans+=zeros;
    else if(X[i]==2)
    {
      int it=upper_bound(Y,Y+N,2)-Y;
      if(it!=N)
        ans+=N-it;
      ans-=threes;
      ans-=four;
      ans+=zeros+ones;
    }
    else
    {
      int it=upper_bound(Y,Y+N,X[i])-Y;
      if(it!=N)
      ans+=N-it;
      ans+=zeros+ones;
      if(X[i]==3)
      ans+=twos;
    }
  }
  return ans;
}

int main()
{
  int m,n;
  cin>>m>>n;
  int x[m],y[n];
  for(int i=0;i<m;i++)
  cin>>x[i];
  for(int i=0;i<n;i++)
  cin>>y[i];
  cout<<countPairs(x,y,m,n);
}
