#include<bits/stdc++.h>
using namespace std;

int kadensAlgo(int arr[],int n)
{
  int ans=INT_MIN;
  int curr_sum=0;
  for(int i=0;i<n;i++)
  {
    curr_sum+=arr[i];
    if(curr_sum>ans)
    ans=curr_sum;
    if(curr_sum<0)
    curr_sum=0;
  }
  return ans;
}

int circularSubarraySum(int arr[], int num)
{
  if(num<=2)
    return kadensAlgo(arr,num);
  else
  {
    int sum_without_wraping=kadensAlgo(arr,num);
    int sum=0;
    for(int i=0;i<num;i++)
    {
      sum+=arr[i];
      arr[i]=arr[i]*-1;
    }
    int sum_with_wraping=sum-kadensAlgo(arr,num)*-1;
    return max(sum_without_wraping,sum_with_wraping);
  }
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  cout<<circularSubarraySum(arr,n)<<endl;
}
