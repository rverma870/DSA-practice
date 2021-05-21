#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
  sort(arr,arr+n);
  sort(dep,dep+n);
  int i=1,j=0,ans=1,temp=1;
  while(i<n && j<n)
  {
    if(arr[i]>dep[j])
    {
      j++;
      temp--;
    }
    else
    {
      i++;
      temp++;
      ans=max(ans,temp);
    }
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  int arr[n],dep[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  for(int i=0;i<n;i++)
    cin>>dep[i];
  cout<<findPlatform(arr,dep,n);
}
