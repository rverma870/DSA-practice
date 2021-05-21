#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define M 1000000007
long long int inverse(long long int i)
{
    if(i==1) return 1;
    return (M - ((M/i)*inverse(M%i))%M+M)%M;
}

ll exposolver(ll a , ll b)
{
  ll res=1;
  while(b>0)
  {
    if(b&1==1)
      res=(res%M*a%M)%M;
    a=(a%M*a%M);
    b=b>>1;
  }
  return res;
}
int main()
{
  ll n,x,k,NOD=1,sum=1,prod=1,total=0;
  cin>>n;
  vector<pair<ll,ll>>v;
  for(int i=0;i<n;i++)
  {
    cin>>x>>k;
    total=(total%M+k%M)%M;
    v.push_back(make_pair(x,k));
    NOD=(NOD%M*(k+1)%M)%M;
    sum=(sum%M * ((exposolver(x,k+1)-1)%M *(inverse(x-1))%M)%M)%M;
  }
  for(auto e:v)
  {
    k=e.second;
    x=e.first;
    //prod=(prod%M * exposolver(x,(((k%M)*(k+1)%M *(total%M - k%M + 1))%M * (inverse(2)))%M)%M)%M;
    prod=(prod%M * exposolver(x,((k%M * NOD)%M * inverse(2))%M)%M)%M;
  }
  cout<<NOD<<" "<<sum<<" "<<prod<<endl;
}
