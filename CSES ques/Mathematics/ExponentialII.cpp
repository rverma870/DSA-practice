//This que is done by fermet's theorem refer gfg for this solution.->" https://www.geeksforgeeks.org/find-power-power-mod-prime/ "
//plz dont open this que again.

#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    long long a,b,c,res=1;
    cin>>a>>b>>c;
    while(c>0)
    {
      if(c&1!=0)
        res=(res%(M-1)*b%(M-1))%(M-1);
      b=(b%(M-1)*b%(M-1))%(M-1);
      c=(c>>1);
    }
    b=res;
    res=1;
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
