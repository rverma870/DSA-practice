#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n ,temp=5 , ans=0;
  cin>>n;
  while(n/temp)
  {
    ans+=n/temp;
    temp=temp*5;
  }
  cout<<ans<<"\n";
}
