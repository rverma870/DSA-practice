#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll temp=0;
ll merge(ll a[],ll l,ll mid,ll r)
{
  ll n1=mid-l+1 , n2=r-mid;
  ll x[n1],y[n2];
  for(ll i=0;i<n1;i++)
    x[i]=a[l+i];
  for(ll i=0;i<n2;i++)
    y[i]=a[mid+1+i];
  ll i=0,j=0,k=l;
  while(i<n1 && j<n2)
  {
    if(x[i]<=y[j])
    {
      a[k]=x[i];
      i++;
      k++;
    }
    else
    {
      a[k]=y[j];
      temp+=n1-i;
      k++;
      j++;
    }
  }
  while(i<n1)
  {
    a[k]=x[i];
    k++;
    i++;
  }
  while(j<n2)
  {
    a[k]=y[j];
    k++;
    j++;
  }
}

void mergesort(ll a[],ll l,ll r)
{
  if(l<r)
  {
    ll mid=(l+r)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    merge(a,l,mid,r);
  }
}

int main()
{
  ll n;
  cin>>n;
  ll arr[n];
  for(ll i=0;i<n;i++)
    cin>>arr[i];
  mergesort(arr,0,n-1);
  cout<<temp;
}
