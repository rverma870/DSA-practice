#include<bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n)
{
  if(n==0)
    return 0;
  long long count=0;
  while(n)
  {
    long long mask= n & -n;
    n-=mask;
    count++;
    if(count>1)
      return false;
  }
  return true;
}

int main()
{
  long long n;
  cin>>n;
  cout<<isPowerofTwo(n);
}
