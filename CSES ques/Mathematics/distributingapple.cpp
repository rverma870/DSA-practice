//using beggar's method
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

ll a[2000001];

long long int inverse(long long int i)
{
    if(i==1) return 1;
    return (M - ((M/i)*inverse(M%i))%M+M)%M;
}

int main()
{
  a[0]=1;
  for(int i=1;i<2000001;i++)
    a[i]=(a[i-1]%M*i)%M;

  ll n,m;
  cin>>n>>m;
  cout<<(a[n+m-1] * inverse(a[m]%M * a[n-1]%M))%M;

}
