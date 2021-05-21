#include<bits/stdc++.h>
using namespace std;

bool canPair(vector<int> nums, int k)
{
  int n=nums.size();
  if(n%2!=0)
    return false;
  unordered_map<int,int>mp;//<remainder,freq>
  for(int i=0;i<n;i++)
    mp[nums[i]%k]+=1;
  for(auto e:mp)
  {
    if(e.first==0)
    {
        if(e.second%2!=0)
        return false;
    }
    else if(e.first*2==k)
    {
        if(e.second%2!=0)
        return false;
    }
    else
    {
      if(e.second!=mp[k-e.first])
      return false;
    }
  }
  return true;
}

int main()
{
  int n,k;
  cin>>n>>k;
  vector<int>nums(n);
  for(int i=0;i<n;i++)
    cin>>nums[i];
  cout<<canPair(nums,k);
}
