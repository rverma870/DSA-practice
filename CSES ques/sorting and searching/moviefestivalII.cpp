// Movie Festival
#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int n,k ;
    cin>> n>>k ;
    array<long,2> a[n] ;
    for(int i=0 ; i<n ; i++ ) cin>>a[i][1]>>a[i][0];
    sort(a,a+n) ;
    int count=1 ;
    multiset<long> mem ;
    mem.insert(a[0][0]) ;
    for( int i=1 ; i<n ; i++ )
    {
        auto it = mem.lower_bound(a[i][1]+1) ;
        if(it!=mem.begin())
        {
            it-- ;
            count++ ;
            mem.erase(it) ;
            mem.insert(a[i][0]) ;
        }
        else if(mem.size()<k)
        {
            mem.insert(a[i][0]) ;
            count++ ;
        }
    }
    cout<<count<<"\n" ;
}
