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
  a[0]=1;
  for(int i=1;i<1000001;i++)
    a[i]=(a[i-1]%M*i)%M;
  string s;
  cin>>s;
  ll countarr[26]={0};
  ll l=s.length();
  ll ans=a[l];
  for(int i=0;i<l;i++)
  {
    countarr[int(s[i])-97]+=1;
  }
  for(int i=0;i<26;i++)
  {
    ans=(ans%M * inverse(a[countarr[i]])%M)%M;
  }
  cout<<ans<<endl;
}
