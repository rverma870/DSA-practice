#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  int n ;
  cin>>n ;
  long x , temp;
  cin>>x ;
  map<long,int> a ;
  a[0]=1 ;
  long sum=0 ,ans=0 ;
  for( int i=0 ; i<n ;i++ )
  {
    cin>>temp ;
    sum+=temp ;
    ans+=a[sum-x] ;
    a[sum]++ ;
  }
  cout<<ans<<"\n" ;
}
