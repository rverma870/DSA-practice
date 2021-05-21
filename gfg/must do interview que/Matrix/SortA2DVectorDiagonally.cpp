#include<bits/stdc++.h>
using namespace std;

void diagonalSort(vector<vector<int> >& matrix, int n, int m)
{
  vector<int>v;
  for(int gap=1;gap<m;gap++)
  {
    //for upper matrix;
    v.clear();
    for(int i=0, j=gap; i<n && j<m ;i++,j++)
      v.push_back(matrix[i][j]);

    sort(v.begin(),v.end(),greater<int>());
    for(int i=0, j=gap; i<n && j<m ;i++,j++)
      matrix[i][j]=v[i];
  }

  for(int gap=1;gap<n;gap++)
  {
    //for lower matrix;
    v.clear();
    for(int i=gap,j=0;i<n && j<m; i++,j++)
    v.push_back(matrix[i][j]);

    sort(v.begin(),v.end());
    for(int i=gap,j=0;i<n && j<m ;i++,j++)
    matrix[i][j]=v[j];
  }
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
  diagonalSort(matrix,n,m);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    cout<<matrix[i][j]<<" ";
    cout<<endl;
  }
}
