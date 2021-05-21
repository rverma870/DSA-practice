#include<bits/stdc++.h>
using namespace std ;
int main()
{
  int n , x  , t;
  bool ans = true ;
  cin>>n>>x;
  vector<pair<int,int>> data ;
  for( int i=0 ; i<n ; i++)
  {
    cin>>t ;
    data.push_back(make_pair(t,i+1)) ;
  }
  sort(data.begin(),data.end());
  int i=0 , j=n-1 ;

  while(i<j)
  {
    int sum= data[i].first+data[j].first ;
    if(sum==x)
    {
      cout<<data[i].second<<" "<<data[j].second<<"\n";
      ans=false ;
      break ;
    }
    else if(sum>x)
      j-- ;
    else
      i++ ;
  }

  if(ans)
    cout<<"IMPOSSIBLE\n" ;
}
