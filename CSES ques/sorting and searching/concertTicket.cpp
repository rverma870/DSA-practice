#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n , c ,x ;
    cin>>n>>c ;
    multiset<int> s ;
    for( int i=0 ; i<n ; i++)
    {
        cin>>x;
        s.insert(x) ;
    }
    for( int i=0 ; i<c;i++)
    {
        cin>>x ;
        auto it = s.lower_bound(x+1) ;
        if(it==s.begin())
        {
            cout<<-1<<"\n" ;
            continue ;
        }
        else
        {
            it-- ;
            cout<<*it<<"\n" ;
            s.erase(it) ;
        }

    }
}
