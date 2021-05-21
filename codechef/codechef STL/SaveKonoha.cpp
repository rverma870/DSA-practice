#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,z,count=0;
    cin>>n>>z;
    multiset<long,greater<long>>s;
    for(int i=0;i<n;i++)
    {
      long temp;
      cin>>temp;
      s.insert(temp);
    }
    while(z>0 && !s.empty())
    {
      auto it = s.begin();
      z-=*it;
      count++;
      s.erase(it);
      if(*it/2!=0)
      s.insert(*it/2);
    }
    if(z<=0)
     cout<<count;
    else
    cout<<"Evacuate";
  }
}
