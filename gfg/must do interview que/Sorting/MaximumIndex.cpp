#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(int arr[], int n)
{
  int incre_max[n],incre_min[n];
  incre_max[n-1]=arr[n-1];
  incre_min[0]=arr[0];
  for(int i=1;i<n;i++)
    incre_min[i]=min(incre_min[i-1],arr[i]);
  for(int i=n-2;i>=0;i--)
    incre_max[i]=max(incre_max[i+1],arr[i]);
  int i=0,j=0,ans=0;
  while(i<n && j<n)
  {
    if(incre_max[j]>=incre_min[i])
    {
        ans=max(ans,j-i);
        j++;
    }
    else
      i++;
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
  cout<<maxIndexDiff(arr,n);
}
