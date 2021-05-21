#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums)
{
  int n=nums.size();
  vector<int>ans;
  vector<int>dp(n+1,1);
  if(n==0)
    return ans;
  sort(nums.begin(),nums.end());
  int mx=1;
  for(int i=1;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
      if(nums[i]%nums[j]==0 && dp[j]+1>dp[i])
      {
        dp[i]=dp[j]+1;
        if(dp[i]>mx)
          mx=dp[i];
      }
    }
  }
  int prev=-1;
  for(int i=n-1;i>=0;i--)
  {
    if(dp[i]==mx && (prev%nums[i]==0 || prev==-1))
    {
      ans.push_back(nums[i]);
      mx--;
      prev=nums[i];
    }
  }
  return ans;
}

int main()
{
  vector<int>nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  vector<int>x=largestDivisibleSubset(nums);
  for(auto e:x)
  cout<<e<<" ";
}
