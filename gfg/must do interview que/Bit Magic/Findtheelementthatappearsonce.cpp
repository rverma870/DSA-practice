#include<bits/stdc++.h>
using namespace std;

int search(int A[], int N)
{
  int ans=0;
  for(int i=0;i<N;i++)
  {
    ans=ans^A[i];
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
  cout<<search(arr,n);
}
