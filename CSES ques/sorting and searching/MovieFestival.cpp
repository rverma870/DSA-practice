#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,count=1;
  cin>>n;
  vector<pair<long,long>>v;
  for(int i=0;i<n;i++)
  {
    long a,b;
    cin>>a>>b;
    v.push_back(make_pair(b,a));
  }
  sort(v.begin(),v.end());
  int i=0,j=1;
  while(j<n)
  {
    if(v[i].first<=v[j].second)
     {
       count++;
       i=j;
       j++;
     }
    else
    j++;
  }
  cout<<count<<endl;
}
