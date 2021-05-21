#include<bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n)
{
  for(int i=0;i<n;i++)
    if(arr[i]==0)
      arr[i]=-1;
  unordered_map<int,int>mp;
  int sum=0,i=-1,ans=0;
  mp[0]=-1;
  while(i<n-1)
  {
    i++;
    sum+=arr[i];
    if(mp.find(sum)!=mp.end())
    {
      if(i-mp[sum]>ans)
      ans=i-mp[sum];
    }
    else
    mp[sum]=i;
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<maxLen(arr,n);
}
