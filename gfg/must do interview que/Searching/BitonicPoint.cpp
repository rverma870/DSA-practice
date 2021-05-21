#include<bits/stdc++.h>
using namespace std;

int findMaximum(int arr[], int n)
{
    int l=0,h=n-1,mid,ans=arr[0];
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
        {
          l=mid+1;
          ans=arr[mid];
        }
        else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        {
          ans=arr[mid];
          break;
        }
        else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])
        {
          h=mid-1;
        }
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
  cout<<findMaximum(arr,n);
}
