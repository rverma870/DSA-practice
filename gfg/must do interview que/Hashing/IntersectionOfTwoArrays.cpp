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
int NumberofElementsInIntersection (int a[], int b[], int n, int m )
{
  set<int>st;
  sort(b,b+m);
  for(int i=0;i<n;i++)
  {
    if(binarysearch(b,m,a[i]))
      st.insert(a[i]);
  }
  return st.size();
}

int main()
{
  int n,m;
  cin>>n>>m;
  int a[n],b[m];
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<m;i++)
    cin>>b[i];
  cout<<NumberofElementsInIntersection (a,b,n,m);
}
