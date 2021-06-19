#include <bits/stdc++.h>
using namespace std;

int maximumPath(int n, vector<vector<int>> matrix)
{
  for(int i=1;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(j>0 && j<n-1)
        matrix[i][j]+=max(matrix[i-1][j-1],max(matrix[i-1][j],matrix[i-1][j+1]));
      else if(j<n-1)
        matrix[i][j]+=max(matrix[i-1][j],matrix[i-1][j+1]);
      else if(j>0)
        matrix[i][j]+=max(matrix[i-1][j-1],matrix[i-1][j]);
    }
  }
  int ans=0;
  for(int i=0;i<n;i++)
    ans=max(ans,matrix[n-1][i]);
  return ans;
}

int main()
{
  int N;
  cin>>N;
  vector<vector<int>> Matrix(N, vector<int>(N, 0));
  for(int i = 0;i < N*N;i++)
      cin>>Matrix[(i/N)][i%N];
  cout<<maximumPath(N, Matrix)<<"\n";
}
