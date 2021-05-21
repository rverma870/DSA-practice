#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n,t,temp,l=1,h=1e18,mid;
  cin>>n>>t;
  long long a[n] , ans;
  for(int i=0;i<n;i++)
   cin>>a[i];
   while(l<=h)
   {
     mid = (l+h)/2 ;
     temp=0 ;
     for( long long i=0 ; i<n ; i++ )
     {
       temp += mid/a[i] ;
       if(temp>=t)
        break;
     }
     if(temp>=t)
     {
       ans=mid;
       h=mid-1;
     }
     else
      l = mid+1 ;
   }
   cout<<ans;
 }
