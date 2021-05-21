#include<bits/stdc++.h>
using namespace std;

int main()
{
  long n;
  cin>>n;
  long a[n];
  if(n<=3&& n>1)
  cout<<"NO SOLUTION";
  else if(n==1)
  cout<<1;
  else if(n%2==1)
  {
    for(long i=n;i>=1;i-=2)
    {
      cout<<i<<" ";
    }
    for(long i=n-1;i>=1;i-=2)
    {
      cout<<i<<" ";
    }
  }
  else
  {
    for(long i=n-1;i>=1;i-=2)
    {
      cout<<i<<" ";
    }
    for(long i=n;i>=1;i-=2)
    {
      cout<<i<<" ";
    }
  }
}
