#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
bool check(ll mid,ll a[])
{
  ll sum=0,subarraycount=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]>mid)
      return false;
    if(sum+a[i]<=mid)
      sum+=a[i];
    else
    {
      sum=a[i];
      subarraycount++;
    }
  }
  subarraycount++;
  return (subarraycount<=k);
}

int main()
{
  cin>>n>>k;
  ll a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  ll l=1,r=2e14;
  while(l<r)
  {
    ll mid=(l+r)/2;
    if(check(mid,a))
      r=mid;
    else
      l=mid+1;
  }
  cout<<l;

}
