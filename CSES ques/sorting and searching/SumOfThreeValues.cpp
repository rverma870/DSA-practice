#include<bits/stdc++.h>
using namespace std;
typedef  long long  ull ;
int main()
{
  ull n,x;
  cin>>n>>x;
  vector<pair<ull,ull>>v;
  for(int i=0;i<n;i++)
  {
    ull temp;
    cin>>temp;
    v.push_back(make_pair(temp,i+1));
  }
  sort(v.begin(),v.end());
  bool check =true ;
  int i=0 , j=0 , k=0 ;
  ull search = 0;
  for(  k=n-1 ; k>1 ; k--)
  {
    if(v[k].first>=x)
      continue ;
    else
    {
      search = x-v[k].first ;
      i=0 ;
      j=k-1 ;
      while(i<j)
      {
        ull sum2 = v[i].first+v[j].first;
        if(sum2>search)
          j-- ;
        if(sum2<search)
          i++ ;
        if(sum2==search)
        {
          cout<<v[i].second<<" "<<v[j].second<<" "<<v[k].second<<'\n' ;
          check=false ;
          break;
        }
      }
      if(!check)
        break ;
    }
  }
  if(check) cout<<"IMPOSSIBLE\n" ;
}
