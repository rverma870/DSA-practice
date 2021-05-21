#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int>nums;
  nums.push_back(200);
  nums.push_back(3);
  nums.push_back(140);
  nums.push_back(20);
  nums.push_back(10);
  // nums.push_back(1);
  // nums.push_back(100);

  int n=nums.size();
  if(n==0)
   return 0;
  if(n==1)
   return nums[0];
  int dp1[n],dp2[n];
  memset(dp1,-1,sizeof(dp1));
  memset(dp2,-1,sizeof(dp2));

  dp1[0]=nums[0];
  dp1[1]=nums[0];

  for(int i=2;i<n-1;i++)
    dp1[i]=max(nums[i]+dp1[i-2],dp1[i-1]);

  dp2[0]=0;
  dp2[1]=nums[1];

  for(int i=2;i<n;i++)
    dp2[i]=max(nums[i]+dp2[i-2],dp2[i-1]);

  cout<<max(dp1[n-2],dp2[n-1]);

}
