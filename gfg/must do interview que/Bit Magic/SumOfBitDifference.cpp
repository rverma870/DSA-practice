#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long LL;
int countBits(int N, long long int A[])
{
  int ans=0;
  for(int i=0; i<31; i++)
  {
    LL count=0;
    for(int j=0; j<N; j++)
    {
      if((A[j]&(1<<i)))
      count++;
    }
    ans += (count*((LL)N-count)*2)%M;
    ans%=M;
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  long long int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<countBits(n,arr);
}
