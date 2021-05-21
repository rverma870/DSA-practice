#include<bits/stdc++.h>
using namespace std ;
int main()
{
  int n ,k;
  cin>>n>>k ;
  multiset<long> x ;
  long a[n] ;

  for( int i=0 ; i<n ; i++ ) cin>>a[i] ;

  for(int i=0;i<k;i++)
    x.insert(a[i]);

  int len = (k+1)/2 -1 ;

  auto itmed = x.begin() ;

  while(len--)
    itmed++ ;

  long med = *itmed ;

  cout<<med<<" " ;

  long i=1,j=i+k-1;
  while(j<n)
  {
    long add,rem;
    add=a[j];
    rem=a[i-1];
    x.insert(add);
    if(add>=med && rem<=med)
      itmed++;
    if(add<med && rem>=med)
      itmed-- ;
    med=*itmed;
    cout<<med<<" ";
    auto del = x.find(rem) ;

    if(del==itmed)
      itmed++ ;
    x.erase(del) ;

    j++;
    i++;
  }
}
