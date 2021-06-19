#include<bits/stdc++.h>
using namespace std;

long long int solve(int a[],int n,int sum,long long int dp[][1001])
{
  long long int count;
  if(sum==0)
    return 1;
  if(sum<0)
    return 0;
  if(sum>0 && n<=0)
    return 0;
  if(dp[n][sum]!=-1)
    return dp[n][sum];
  if(a[n-1]<=sum)
  count=solve(a,n,sum-a[n-1],dp)+solve(a,n-1,sum,dp);
  else
   count=solve(a,n-1,sum,dp);
  return dp[n][sum]=count;
}

long long int count( int S[], int m, int n )
{
    long long int dp[1001][1001];
    memset(dp,-1,sizeof(dp));
    return solve(S,m,n,dp);
}

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[m];
	for(int i=0;i<m;i++)
	    cin>>arr[i];
  cout<<count(arr,m,n);
}
