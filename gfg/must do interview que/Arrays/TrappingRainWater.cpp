#include<bits/stdc++.h>
using namespace std;

int trappingWater(int arr[], int n)
{
  int l[n],r[n];
  l[0]=arr[0];
  r[n-1]=arr[n-1];
  for(int i=1;i<n;i++)
  {
    l[i]=max(arr[i],l[i-1]);
    r[n-1-i]=max(arr[n-1-i],r[n-i]);
  }
  int ans=0;
  for(int i=1;i<n-1;i++)
  {
    ans+=min(l[i],r[i])-arr[i];
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
  cout<<trappingWater(arr,n);
}
