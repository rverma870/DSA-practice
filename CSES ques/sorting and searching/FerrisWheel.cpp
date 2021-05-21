#include<bits/stdc++.h>
using namespace std;

int main()
{
  long n,x,ans=0;
  cin>>n>>x;
  long a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  sort(a,a+n);
  int i=0,j=n-1;
  while(i<=j)
  {
    if(i==j)
    {
      ans++;
      break;
    }
    else if(a[i]+a[j]>x)
    {
      ans++;
      j--;
    }
    else
    {
      ans++;
      i++;
      j--;
    }
  }
  cout<<ans;
}
