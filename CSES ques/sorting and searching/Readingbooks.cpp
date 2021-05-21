#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
ll n;cin>>n;
ll sum=0,ma=INT_MIN;
for(int i=0;i<n;++i)
{
 ll x;cin>>x;
 sum+=x;
 ma=max(ma,x);
}
cout<<(ma>(sum-ma)?2*ma:sum)<<endl;
}
