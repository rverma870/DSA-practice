#include<bits/stdc++.h>
using namespace std ;
int main()
{
  int n ,k;
  cin>>n>>k ;
  multiset<long> x ;
  long a[n],cost=0 ;

  for( int i=0 ; i<n ; i++ ) cin>>a[i] ;

  for(int i=0;i<k;i++)
    x.insert(a[i]);

  int len = (k+1)/2 -1 ;

  auto itmed = x.begin() ;

  while(len--)
    itmed++ ;

  long med = *itmed ;

  for(auto e:x)
    cost+=labs(e-med);
  cout<<cost<<" ";
  long i=1,j=i+k-1;
  while(j<n)
  {
    long add,rem;
    add=a[j];
    rem=a[i-1];
    long remcost,oldmed;
    oldmed=med;
    remcost=abs(rem-oldmed);
    x.insert(add);
    if(add>=med && rem<=med)
      itmed++;
    if(add<med && rem>=med)
      itmed-- ;

    med=*itmed;

    long addcost,newmed;
    newmed=med;
    addcost=abs(add-newmed);
    if(k%2==0)
      cost=abs(cost-remcost)+addcost-(newmed-oldmed);
    else
      cost=abs(cost-remcost)+addcost;
    cout<<cost<<" ";
    auto del = x.find(rem);

    if(del==itmed)
      itmed++ ;
    x.erase(del) ;

    j++;
    i++;
  }
}
