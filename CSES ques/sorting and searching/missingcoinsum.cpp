#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n,sum=0;
  cin>>n;
  long long a[n];
  for(long long i=0;i<n;i++)
  cin>>a[i];
  sort(a,a+n);
  for(int i=0;i<n;i++)
  {
    if(a[i]>sum+1)
    break;
    else
      sum+=a[i];
  }
  cout<<sum+1;
}
