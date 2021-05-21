#include<bits/stdc++.h>
using namespace std;

vector<int> topK(vector<int>& nums, int k)
{
  vector<int>ans;
  int n=nums.size();
  map<int,int>mp;
  for(int i=0;i<n;i++)
  mp[nums[i]]+=1;
  vector<pair<int,int>>temp;
  for(auto e:mp)
  {
    pair<int,int>p;
    p.first=e.second;
    p.second=e.first;
    temp.push_back(p);
  }
  sort(temp.rbegin(),temp.rend());
  int i=0;
  for(auto e:temp)
  {
    ans.push_back(e.second);
    i++;
    if(i==k)
    break;
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  vector<int>nums(n),ans;
  for(int i=0;i<n;i++)
    cin>>nums[i];
  int k;
  cin>>k;
  ans=topK(nums,k);
  for(auto e:ans)
    cout<<e<<" ";

}
