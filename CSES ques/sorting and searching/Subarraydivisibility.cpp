#include<bits/stdc++.h>
using namespace std ;
int main()
{
    long n ;
    cin>>n ;
    map<long,int> a;
    a[0] = 1 ;
    long long ans =0 , x , sum=0;
    for( int i=0 ; i<n ; i++)
    {
        cin>>x ;
        sum+=x ;
        ans+=a[(n+sum%n)%n];
        a[(n+sum%n)%n]++ ;
    }
    cout<<ans<<"\n" ;
}
