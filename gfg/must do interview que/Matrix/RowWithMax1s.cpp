#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m)
{
  int count=0,it,ans;
  for(int i=0;i<n;i++)
  {
    it=lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
    if(m-it>count)
    {
      ans=i;
      count=m-it;
    }
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
  cout<<rowWithMax1s(matrix,n,m);
}
