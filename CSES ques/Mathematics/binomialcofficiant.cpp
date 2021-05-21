#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

ll a[1000001];


long long int inverse(long long int i)
{
    if(i==1) return 1;
    return (M - ((M/i)*inverse(M%i))%M+M)%M;
}
int main()
{
  ll n,x,y;
  cin>>n;
  a[0]=1;
  for(int i=1;i<1000001;i++)
    a[i]=(a[i-1]%M*i)%M;
  for(int i=0;i<n;i++)
  {
    cin>>x>>y;
    cout<<(a[x]%M * inverse((a[y]%M * a[x-y]%M)%M))%M<<endl;
  }

}
