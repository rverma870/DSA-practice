#include<bits/stdc++.h>
using namespace std;

int findSingle(int N, int arr[])
{
    int ans=0;
    for(int i=0;i<N;i++)
    {
        ans=ans^arr[i];
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
  cout<<findSingle(n,arr);
}
