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
           return 1;
    }
    return 0;
}
int findSwapValues(int A[], int n, int B[], int m)
{
  int sum1=0,sum2=0;
  for(int i=0;i<n;i++)
    sum1+=A[i];
  for(int i=0;i<m;i++)
    sum2+=B[i];
  if ((sum1 - sum2) % 2 != 0)
       return -1;
  int find=(sum1-sum2)/2;
  sort(B,B+m);
  for(int i=0;i<n;i++)
  {
    if(binarysearch(B,m,A[i]-find))
      return 1;
  }
  return -1;
}

int main()
{
  int n,m;
  cin>>n>>m;
  int A[n],B[m];
  for(int i=0;i<n;i++)
    cin>>A[i];
  for(int i=0;i<m;i++)
    cin>>B[i];
  cout<<findSwapValues(A,n,B,m);
}
