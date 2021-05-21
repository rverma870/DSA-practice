#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin>>n;
  vector<pair<ll,ll>>v;
  for(ll i=0;i<n;i++)
  {
    ll temp;
    cin>>temp;
    if(v.empty())
    {
      v.push_back(make_pair(temp,i+1));
      cout<<0<<" ";
    }
    else
    {
      if(v.back().first<temp)
      {
        cout<<v.back().second<<" ";
        v.push_back(make_pair(temp,i+1));
      }
      else
      {
        while(v.back().first>=temp and !v.empty())
        {
          v.pop_back();
        }
        if(!v.empty())
          cout<<v.back().second<<" ";
        else
        cout<<0<<" ";
        v.push_back(make_pair(temp,i+1));
      }
    }
  }
}
