#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(int arr[], int n)
{
    vector<pair<int,int>>m(n);
    for(int i=0;i<n;i++)
        m[i]=make_pair(arr[i],i);
    int minimum=INT_MAX;
    int ans=0;
    sort(m.begin(),m.end());
    for(auto e:m)
    {
        minimum=min(minimum,e.second);
        ans=max(ans,e.second-minimum);
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
  cout<<maxIndexDiff(arr,n);

}
