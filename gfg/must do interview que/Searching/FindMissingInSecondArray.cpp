#include<bits/stdc++.h>
using namespace std;

int binarysearch(long long arr[], int n, long long k)
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


vector<long long> findMissing(long long A[], long long B[], int N, int M)
{
  vector<long long>ans;
  sort(B,B+M);
  for(int i=0;i<N;i++)
  {
    if(binarysearch(B,M,A[i])==-1)
      ans.push_back(A[i]);
  }
  return ans;
}

int main()
{
  int N,M;
  cin>>N>>M;
  long long A[N],B[M];
  for(int i=0;i<N;i++)
  cin>>A[i];
  for(int i=0;i<M;i++)
  cin>>B[i];
  vector<long long>ans;
  ans=findMissing(A,B,N,M);
  for(auto e:ans)
    cout<<e<<" ";
  //cout<<binarysearch(B,M,3)<<endl;
}
