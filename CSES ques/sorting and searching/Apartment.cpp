#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n,m,k,x,ans=0;
  cin>>n>>m>>k;
  long long a[n],ap[m];
  for(long i=0;i<n;i++)
   cin>>a[i];
  for(long i=0;i<m;i++)
   {
    cin>> ap[i];
   }
  sort(ap,ap+m);
  sort(a,a+n);
  int i=0,j=0;
  while(i<n && j<m)
  {
    if(ap[j]>a[i]+k)
    {
      i++;
    }
    else if(ap[j]<a[i]-k)
    {
      j++;
    }
    else
    {
      i++;
      j++;
      ans++;
    }

  }
   cout<<ans;
}
