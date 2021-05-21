#include<bits/stdc++.h>
using namespace std;

int main()
{
  long n,x,ans=0;
  cin>>n;
  long a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  sort(a,a+n);
  x=n/2;
  for(int i=0;i<n;i++)
  {
    ans+=abs(a[i]-a[x]);
  }
  cout<<ans;
}
