#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z)
{
    int cut[3] ;
    cut[0] = x ;
    cut[1] = y ;
    cut[2] = z ;

    int dp[4][n+1] ;
    for( int i=0 ; i<=n ; i++ ) dp[0][i] = 0 ;
    for( int i=0 ; i<4 ; i++)   dp[i][0] = 0;

    for( int i=1 ; i<4 ; i++ )
        for( int j=1 ; j<=n ; j++)
            if(j>=cut[i-1]and (dp[i][j-cut[i-1]]!=0 or j-cut[i-1]==0))
                dp[i][j] = max(1+dp[i][j-cut[i-1]],dp[i-1][j]) ;
            else
                dp[i][j] = dp[i-1][j];

    return dp[3][n] ;
}

int main()
{
  int n;
  cin >> n;
  int x,y,z;
  cin>>x>>y>>z;
  cout<<maximizeTheCuts(n,x,y,z)<<endl;
}
