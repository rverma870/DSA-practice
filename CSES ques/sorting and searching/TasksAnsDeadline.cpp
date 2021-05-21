#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n ;
  cin>>n ;
  array<long,2> a[n] ;
  for(int i=0 ; i<n ; i++) cin>>a[i][0]>>a[i][1];
  sort(a,a+n) ;
  long reward = 0 , timer =0 ;

  for(int i=0 ; i<n ; i++)
  {
    timer+=a[i][0] ;
    reward += a[i][1]-timer ;
  }
  cout<<reward<<"\n" ;
}
