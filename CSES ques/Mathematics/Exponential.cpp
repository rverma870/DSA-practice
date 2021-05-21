#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    long long a,b,res=1;
    cin>>a>>b;
    while(b>0)
    {
      if(b&1!=0)
        res=(res%(M)*a%(M))%(M);
      a=(a%(M)*a%(M))%(M);
      b=(b>>1);
    }
    cout<<res<<endl;
  }
}
