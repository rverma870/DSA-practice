// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

long long int nthFibonacci(long long int n){

    long long int dp[n+1];
    int M=1000000007;
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=(dp[i-1]%M+dp[i-2]%M)%M;
    return dp[n];
}
int main()
{
  long long int n;
  cin >> n;
  cout<<nthFibonacci(n) << endl;
}
