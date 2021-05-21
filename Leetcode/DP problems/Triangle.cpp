#include<bits/stdc++.h>
using namespace std;

int MX=1000000;
int minimumTotal(vector<vector<int>>& triangle)
{
    int r=triangle.size();
    vector<vector<int>>dp(r);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<triangle[i].size();j++)
        {
            dp[i].push_back(MX);
        }
    }
    dp[0][0]=triangle[0][0];
    for(int i=0;i<r-1;i++)
    {
        for(int j=0;j<triangle[i].size();j++)
        {
            if(dp[i][j]+triangle[i+1][j]<dp[i+1][j])
              dp[i+1][j]=dp[i][j]+triangle[i+1][j];
            if(dp[i][j]+triangle[i+1][j+1]<dp[i+1][j+1])
              dp[i+1][j+1]=dp[i][j]+triangle[i+1][j+1];
        }
    }
    int ans=MX;
    for(int i=0;i<triangle[r-1].size();i++)
    {
        if(dp[r-1][i]<ans)
         ans=dp[r-1][i];
    }
    cout<<ans;
}

int main()
{
  vector<vector<int>>triangle(4);
  triangle[0].push_back(2);
  triangle[1].push_back(3);
  triangle[1].push_back(4);
  triangle[2].push_back(6);
  triangle[2].push_back(5);
  triangle[2].push_back(7);
  triangle[3].push_back(4);
  triangle[3].push_back(1);
  triangle[3].push_back(8);
  triangle[3].push_back(3);
  minimumTotal(triangle);

}
