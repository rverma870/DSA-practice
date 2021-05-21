#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll findSubarray(vector<ll> arr, int n )
{
  unordered_map<ll,ll>mp;
  ll sum=0,i=-1,count=0;
  mp[0]=1;
  while(i<n-1)
  {
    i++;
    sum+=arr[i];
    if(mp.find(sum)!=mp.end())
      count+=mp[sum];
    mp[sum]+=1;
  }
  return count;
}

int main()
{
  int n;
  cin>>n;
  vector<ll>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<findSubarray(arr,n);
}
