#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll ;
int main()
{
  ll n,x;
  cin>>n>>x;
  vector<pair<ll,ll>>v;
  bool b=false;
  for(int i=0;i<n;i++)
  {
    ll temp;
    cin>>temp;
    v.push_back(make_pair(temp,i+1));
  }
  sort(v.begin(),v.end());
  for(int i=n-1;i>=0;i--)
  {
    if(v[i].first>=x)
    continue;
    else
    for(int j=i-1;j>=0;j--)
    {
      ll sum1=v[i].first+v[j].first;
      //cout<<v[i].first<<" "<<v[j].first<<" ";
      if(sum1>=x)
      continue;
      else
      {
        int k=0,l=j-1;
        ll search=x-sum1;
        while(k<l)
        {
          ll sum2=v[k].first+v[l].first;
        //  cout<<v[k].first<<" "<<v[l].first<<endl;
          if(sum2==search)
          {
            cout<<v[i].second<<" "<<v[j].second<<" "<<v[k].second<<" "<<v[l].second;
            b=true;
            break;
          }
          else if(sum2>search)
          l--;
          else
          k++;
        }
        if(b)
        break;
      }
    }
    if(b)
    break;
  }
  if(!b)
  cout<<"IMPOSSIBLE";
}
