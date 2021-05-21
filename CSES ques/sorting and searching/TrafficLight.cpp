#include<bits/stdc++.h>
using namespace std;

int main()
{
  long x,n,freq=1;
  cin>>x>>n;
  long a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  set<long>s;
  s.insert(0);
  s.insert(x);
  map<long,long>m;
  m[x]=1 ;
  for(int i=0;i<n;i++)
  {
    auto it = s.lower_bound(a[i]);
    int temp1= abs(*it- a[i]);
    it--;
    int temp2=abs(*it-a[i]);
    if(m[temp2+temp1]==1)
    {
      m.erase(temp1+temp2);
    }
    else
    {
      m[temp1+temp2]--;
    }
    m[temp1]++;
    m[temp2]++;
    s.insert(a[i]);
    auto ansit= m.end();
    ansit--;
    cout<<ansit->first<<" ";

  }
}
