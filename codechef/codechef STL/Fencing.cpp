#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long n,m,k,adjcount=0;
    cin>>n>>m>>k;
    set<pair<long,long>> s;
    for(int i=0;i<k;i++)
    {
      long r,c;
      cin>>r>>c;
      s.insert(make_pair(r,c));
      pair<long,long> x;
      x=make_pair(r-1,c) ; //top
      if(s.find(x)!=s.end())
        adjcount++;
      x=make_pair(r+1,c);//bottom
      if(s.find(x)!=s.end())
        adjcount++;
      x=make_pair(r,c-1) ; //left
      if(s.find(x)!=s.end())
          adjcount++;
      x=make_pair(r,c+1) ; //right
      if(s.find(x)!=s.end())
            adjcount++;
    }
    cout<<4*k-adjcount*2<<endl;

  }
}
