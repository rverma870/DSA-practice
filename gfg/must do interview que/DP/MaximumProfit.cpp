#include <bits/stdc++.h>
using namespace std;

int maxProfit(int K, int N, int A[])
{
  int dp[K+1][N];
  for(int i=0;i<N;i++)
  dp[0][i]=0;
  for(int i=0;i<=K;i++)
  dp[i][0]=0;
  for(int t=1;t<=K;t++)
  {
    int m=INT_MIN;
    for(int day=1;day<N;day++)
    {
      if(dp[t-1][day-1]-A[day-1]>m)
        m=dp[t-1][day-1]-A[day-1];
      dp[t][day]=max(dp[t][day-1],m+A[day]);
    }
  }
  return dp[K][N-1];
}
int main()
{
  int N, K;
  cin >> K;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++)
  cin >> A[i];
  cout <<maxProfit(K, N, A) << endl;
}
