#include<bits/stdc++.h>
using namespace std;

int No_of_painter(int arr[],int n,int limited_time)
{
    int total=0,painters=1;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
        if(total>limited_time)
        {
            total=arr[i];
            painters++;
        }
    }
    return painters;
}
long long minTime(int arr[], int n, int k)
{
    int sum=0,max_element=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        max_element=max(max_element,arr[i]);
    }
    int l=max_element,h=sum,painter,mid,ans;
    while(l<=h)
    {
        mid=(l+h)/2;
        painter=No_of_painter(arr,n,mid);
        if(painter>k)
        l=mid+1;
        else
        {
            ans=mid;
            h=mid-1;
        }
    }
    return ans;
}

int main()
{
  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  cout<<minTime(arr,n,k);
}
