// Room Allocation
#include <bits/stdc++.h>
using namespace std ;
int main()
{
    multimap<int,int> room ;
    multimap<pair<int,int>,int> m;
    int n , a, b , r=0;
    cin>>n ;
    vector<int>  ans(n,0) ;
    for( int i=0 ; i<n ; i++)
    {
        cin>>a>>b;
        m.insert(make_pair(make_pair(a,b),i)) ;
    }
    for( auto h:m)
    {
        pair<int,int> z = h.first ;
        int index = h.second ;
        a=z.first ;
        b=z.second;
        auto it = room.lower_bound(a) ;
        if(it!=room.begin())
        {
            it-- ;
            int d = (*it).second ;
            if(d<a)//its compared boz - if more no. of people arived before the arrival of 'a' ,then we have to allocate him a new room
            {
                room.erase(it) ;
                room.insert(pair<int,int>(b,d)) ;
            }
            else
            {
                r++ ;
                d=r ;
                room.insert(make_pair(b,d)) ;
            }
            ans[index] = d  ;
        }
        else
        {
            r++ ;
            room.insert(pair<int,int>(b,r)) ;
            ans[index]=r;
        }
    }
    cout<<*max_element(ans.begin(),ans.end())<<"\n" ;
    for( auto x:ans)
        cout<<x<<" " ;
    cout<<"\n" ;
}
