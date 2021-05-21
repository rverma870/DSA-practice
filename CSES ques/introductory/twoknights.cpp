#include<iostream>
using namespace std;
int main()
{
  long long m,ans;
  cin>>m;

  for(long long n=1;n<=m;n++)
  {
    if(n==1)
    cout<<0<<"\n";
    else if (n==2)
      cout<<6<<"\n";
    else if(n==3)
      cout<<28<<"\n";
    else if (n>=4)
    {
      ans=(n*n*(n*n-1)/2- (4*2 + 8*3 + 4*(n-4)*4 + 4*4 + 4*(n-4)*6 + (n-4)*(n-4)*8)/2);
      cout<<ans<<"\n";
    }
  }

}
