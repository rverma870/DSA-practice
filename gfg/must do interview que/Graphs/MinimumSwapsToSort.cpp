#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums)
{
  int n=nums.size();
  vector<pair<int,int>>v;
  for(int i=0;i<n;i++)
    v.push_back({nums[i],i});
  sort(v.begin(),v.end());
  int ans=0;
  for(int i=0;i<n;i++)
  {
    if(i!=v[i].second)
    {
      ans++;
      swap(v[i],v[v[i].second]);
      i--;
    }
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  vector<int>nums(n);
  for(int i=0;i<n;i++)
  cin>>nums[i];
  cout<<minSwaps(nums);
}
