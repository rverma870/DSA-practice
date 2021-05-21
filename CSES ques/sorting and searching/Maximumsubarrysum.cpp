#include<bits/stdc++.h>
using namespace std;

int main()
{
  long n,x,temp=-1000000000,ans=-1000000000;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    temp=max(temp+x,x);
    ans=max(temp,ans);
  }
  cout<<ans<<endl;
}
