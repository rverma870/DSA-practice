#include<bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix)
{
    int r=matrix.size();
    int c=matrix[0].size();
    int dp[r][c];
    for(int i=0;i<r;i++)
       dp[i][0]=matrix[i][0]-'0';
    for(int i=0;i<c;i++)
       dp[0][i]=matrix[0][i]-'0';
    int ans=0;
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(matrix[i][j]=='0')
              dp[i][j]=0;
            else
              dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
            ans=max(ans,(int)dp[i][j]);
        }
    }
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      cout<<dp[i][j]<<" ";
      cout<<endl;
    }
    return ans*ans;
}

int main()
{
  vector<vector<char>>matrix;
  for(int i=0;i<1;i++)
  {
    vector<char>temp;
    for(int j=0;j<1;j++)
    {
      char x;
      cin>>x;
      temp.push_back(x);
    }
    matrix.push_back(temp);
  }
  // for(int i=0;i<4;i++)
  // {
  //   for(int j=0;j<5;j++)
  //   cout<<matrix[i][j]<<" ";
  //   cout<<endl;
  // }
  cout<<maximalSquare(matrix);
}
