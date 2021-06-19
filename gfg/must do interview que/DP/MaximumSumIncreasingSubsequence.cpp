#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n)
{
  int dp[n];
  for(int i=0;i<n;i++)
    dp[i]=arr[i];

  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<i;j++)
    {
       if(arr[i]>arr[j] && dp[i]<=dp[j]+arr[i])
          dp[i]=dp[j]+arr[i];
     }
  }
  return *max_element(dp,dp+n);
}

int main()
{
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++)
  	cin >> a[i];
  cout<<maxSumIS(a, n);

}
