#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n,sum=0,sum1=0;
  cin>>n;
  long long a[n];
  for(int i=0;i<n-1;i++)
  {
    cin>>a[i];
    sum+=a[i];
  }
  sum1=(n*(n+1))/2;
  cout<<sum1-sum;
}
