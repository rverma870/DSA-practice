#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int,int>mp;
    vector<int>ans;
    priority_queue<pair<int,int>>q;
    for(int i=0;i<nums.size();i++)
      mp[nums[i]]+=1;
    for(auto e:mp)
        q.push(make_pair(e.second,e.first));
    while(k--)
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}

int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  for(auto e:topKFrequent(arr,k))
  cout<<e<<" ";
}
