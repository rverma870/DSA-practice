#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,x,sum=0,ans=0;
  cin>>n>>x;
  ll a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int i=0,j=0;
  sum+=a[i];
  while(i<n or j<n)
  {
    if(sum<x)
    {
      j++;
      sum+=a[j];
    }
    else
    {
      if(sum==x)
      ans++;
      sum-=a[i];
      i++;
      if(sum<x)
        if(j<n)
        {
          j++;
          sum+=a[j];
        }
    }
  }
  cout<<ans;
}
