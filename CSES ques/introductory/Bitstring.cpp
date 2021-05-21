#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
  long long n , ans=2 ;
  cin>>n;
  for(int i=1 ; i<n ; i++)
    ans=((2*ans)%M) ;
  cout<<ans<<"\n" ;
}
