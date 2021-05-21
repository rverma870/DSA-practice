#include<bits/stdc++.h>
using namespace std;
int main()
{
  long n,x;
  cin>>n;
  vector<long> a ;
  for( int i=0 ; i<n ; i++)
  {
    cin>>x;
    auto it = upper_bound(a.begin(),a.end(),x)-a.begin();
    if(it<a.size())
    {
      a[it]=x;
    }
    else
    {
      a.push_back(x) ;
    }
  }
  cout<<a.size()<<"\n" ;
}
