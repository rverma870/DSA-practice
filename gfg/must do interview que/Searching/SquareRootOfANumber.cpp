#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x)
{
    int l=0,h=10000,mid;
    while(l<=h)
    {
      mid=(l+h)/2;
      if(mid*mid==x)
        return mid;
      else if(mid*mid<x)
        l=mid+1;
      else
        h=mid-1;
    }
    if(mid*mid<x)
    return mid;
    else
    return mid-1;
}

int main()
{
  long long int x;
  cin>>x;
  cout<<floorSqrt(x);
}
