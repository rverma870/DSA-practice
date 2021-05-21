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
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int>ans;
    if(binarysearch(B,n2,A[0]) && binarysearch(C,n3,A[0]) )
      ans.push_back(A[0]);
    for(int i=1;i<n1;i++)
    {
      if(A[i]!=A[i-1])
      if(binarysearch(B,n2,A[i]) && binarysearch(C,n3,A[i]) )
        ans.push_back(A[i]);
    }

    if(!ans.empty())
      return ans;
    else
    {
      ans.push_back(-1);
      return ans;
    }
}

int main()
{
  int n1,n2,n3;
  cin>>n1>>n2>>n3;
  int A[n1],B[n2],C[n3];
  for(int i=0;i<n1;i++)
    cin>>A[i];
  for(int i=0;i<n2;i++)
    cin>>B[i];
  for(int i=0;i<n3;i++)
    cin>>C[i];
  vector<int>ans;
  ans=commonElements(A,B,C,n1,n2,n3);
  for(auto e:ans)
  cout<<e<<" ";
}
