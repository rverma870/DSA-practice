#include<bits/stdc++.h>
using namespace std;

void booleanMatrix(vector<vector<int> > &matrix)
{
  int r=matrix.size();
  int c=matrix[0].size();
  unordered_set<int>srow,scol;
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      if(matrix[i][j]==1)
      {
        srow.insert(i);
        scol.insert(j);
      }
    }
  }

  for(auto e:srow)
  {
    for(int i=0;i<c;i++)
      matrix[e][i]=1;
  }
  for(auto e:scol)
  {
    for(int i=0;i<r;i++)
      matrix[i][e]=1;
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
  booleanMatrix(matrix);
  cout<<endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    cout<<matrix[i][j]<<" ";
    cout<<endl;
  }
}
