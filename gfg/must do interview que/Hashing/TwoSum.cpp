#include<bits/stdc++.h>
using namespace std;

bool keypair(vector<int> a, int n, int x)
{
  map<int,int>mp;
  for(int i=0;i<n;i++)
    mp[a[i]]+=1;
  for(auto e:mp)
  {
    if(e.first*2>x)
      return false;
    else if(e.first*2==x )
    {
      if(e.second>1)
      return true;
      else
      return false;
    }
    else if(mp.find(x-e.first)!=mp.end())
        return true;
  }
  return false;
}

int main()
{
  int n,x;
  cin>>n>>x;
  vector<int>A(n);
  for(int i=0;i<n;i++)
  cin>>A[i];
  cout<<keypair(A,n,x);
}
