#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  int temp[n],count=0,l=0,r=n-1;
  for(int i=0;i<n;i++)
  {
      if(arr[i]<0)
      {
          count++;
          temp[l]=arr[i];
          l++;
      }
      else
      {
          temp[r]=arr[i];
          r--;
      }
  }
  int i=0,j=n-1,k=0;
  while(i<count && j>=count)
  {
      arr[k]=temp[j];
      k++;
      j--;
      arr[k]=temp[i];
      k++;
      i++;
  }
  while(j>=count)
  {
      arr[k]=temp[j];
      k++;
      j--;
  }
  while(i<count)
  {
      arr[k]=temp[i];
      k++;
      i++;
  }
  for(auto e:temp)
  cout<<e<<" ";
}
