#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>arr, int n, int k)
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

bool search(vector<vector<int> > matrix, int n, int m, int x)
{
    bool ans=false;
    for(int i=0;i<n;i++)
    {
      if(binarysearch(matrix[i],m,x))
        ans=true;
    }
    return ans;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>>matrix(n);
  for(int i=0;i<n;i++)
  {
    vector<int>temp(m);
    for(int j=0;j<m;j++)
    {
      cin>>temp[j];
    }
    matrix[i]=temp;
  }
  int x;
  cin>>x;
  cout<<search(matrix,n,m,x);
}
