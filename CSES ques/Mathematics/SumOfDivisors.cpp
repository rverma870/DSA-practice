#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long ll  ;
int main()
{
  ll n , ans=0 ;
  cin>>n ;
  ans=n%M ;
  for( ll i=2 ; i<=n ; i++ )
    ans+=((i*(n/i)%M)%M) ;
  cout<<ans<<"\n" ;
}
