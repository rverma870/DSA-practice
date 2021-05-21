#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n,F1,L1,F2,L2,S1,S2;
  cin>>n;
  long long sum=n*(n+1)/2;

  if(sum%2==1)
  cout<<"NO"<<"\n";
  else
  {
    sum=sum/2;
    cout<<"YES"<<"\n";
    cout<<n/2<<"\n";
    if(n%2==0)
    {
      F1=1;
      F2=2;
      L1=n;
      L2=n-1;
      S2=n/2;

    }
    else
    {
      F1=2;
      F2=1;
      L1=n-2;
      L2=n-1;
      S2=n/2+1;
      cout<<n<<" ";

    }
    for(long long i=F1,j=L1;i<j;i+=2,j-=2)
    {
      cout<<i<<" "<<j<<" ";
    }
    cout<<"\n"<<S2<<"\n";

    for(long long i=F2,j=L2;i<j;i+=2,j-=2)
    {
      cout<<i<<" "<<j<<" ";
    }
    }
}
