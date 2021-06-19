#include<bits/stdc++.h>
using namespace std;

int countNum(int res,int arr[],int n)
{
  int count=0;
  for(int i=0;i<n;i++)
  {
    if((res & arr[i])==res)
    {
      count++;
    }
  }
  return count;
}
int maxAND (int arr[], int n)
{
  int res=0;
  for(int i=31;i>=0;i--)
  {
    int count=countNum((res | (1<<i)),arr,n);
    if(count>=2)
      res = (res | (1<<i));
  }
  return res;
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  cout<<maxAND(arr,n);
}
