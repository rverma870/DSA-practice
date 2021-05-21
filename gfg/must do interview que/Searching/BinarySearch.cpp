#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int n, int k)
{
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(arr[mid]<k)
           l=mid+1;
        else if(arr[mid]>k)
           r=mid-1;
        else
           return mid;
    }
    return -1;
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int k;
  cin>>k;
  cout<<binarysearch(arr,n,k);
}
