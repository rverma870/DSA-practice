#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> >& matrix)
{
    int n=matrix.size();
    for(int i=0;i<n;i++)
    {
      for(int j=i;j<n;j++)
      {
        swap(matrix[i][j],matrix[j][i]);
      }
    }
    int t=0,d=n-1;
    while(t<d)
    {
      swap(matrix[t],matrix[d]);
      t++;
      d--;
    }
}

int main()
{
  int n;
  cin>>n;
  vector<vector<int>>matrix(n);
  for(int i=0;i<n;i++)
  {
    vector<int>temp(n);
    for(int j=0;j<n;j++)
    {
      cin>>temp[j];
    }
    matrix[i]=temp;
  }
  rotate(matrix);
  cout<<endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}
