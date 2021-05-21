#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
long long ans=1000000000;
void division(vector<ll> weight,ll n,ll it,ll t,vector<ll>input)
{
  if(it==n)
  {
    long long sum=0;
    for(auto e:input)
    {
      sum+=e;
    }
    ans=min(ans,abs(t-2*sum));
  }
  else
  {
    ll y=weight[0];
    weight.erase(weight.begin());
    division(weight,n,it+1,t,input);
    input.push_back(y);
    division(weight,n,it+1,t,input);

  }
}
int main()
{
  ll n,x,t=0;
  cin>>n;
  vector<ll>weight;
  vector<ll>input;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    weight.push_back(x);
    t=t+weight[i];
  }
  division(weight,n,0,t,input);
  cout<<ans;

}
