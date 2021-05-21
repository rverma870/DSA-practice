#include<bits/stdc++.h>
using namespace std;
vector<int> a(1000001,1);
int main()
{

  long n,x;
  cin>>n;
  a[0]=0;
   for(long i=2;i<1000001;i++)
  {
    for(long j=i;j<1000001;j+=i)
      a[j]+=1;
  }
  for(long i=0;i<n;i++)
  {
     cin>>x;
    cout<<a[x]<<endl;
  }
}
