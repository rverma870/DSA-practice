#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n,count=0;
  cin>>n;
  long long prev , x;
  cin>>prev ;
  for(int i=1;i<n;i++)
  {
    cin>>x ;
    if(x<prev)
    {
      count+=(prev-x) ;
    }
    else
      prev = x ;
  }
  cout<<count;
}
