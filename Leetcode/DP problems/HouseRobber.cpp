#include<bits/stdc++.h>
using namespace std;
int dp[4];
int solve(vector<int>nums,int n,int start)
{
  if(start==n-1)
  return nums[n-1];
  if(start>n-1)
  return 0;
  int ans=0;
  if(dp[start]!=-1)
    return dp[start];
  return dp[start]=max(nums[start]+solve(nums,n,start+2),solve(nums,n,start+1));
}


int main()
{
  vector<int>nums;
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(100);
  int n;
  n=nums.size();
  memset(dp,-1,sizeof(dp));
  cout<<solve(nums,n,0)<<endl;
}
