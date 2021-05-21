#include<bits/stdc++.h>
using namespace std;

int main()
{
  long n , a , b;
  cin>>n>>a>>b;
  multiset<long long> s;
  s.insert(0);
   long long ans = -1e18;
   long long x[n] ,pre[n+1] ;
  pre[0]=0 ;
  for( long i=0 ; i<n ; i++ )
  {
     cin>>x[i] ;
     pre[i+1]=pre[i]+x[i] ;
  }
  s.insert(pre[1]);
    ans=max(ans,pre[a]);

  for( int i=a+1 ; i<n+1 ; i++)
  {
    long add=i-a+1,rem=i-1-b;
    s.insert(pre[add]);
    if(rem>=0)
    {
      auto it=s.find(pre[rem]);
      if(it!=s.end())
      s.erase(it);
    }
    ans=max(ans,pre[i]-*s.begin());
  }
  cout<<ans<<endl;
}
