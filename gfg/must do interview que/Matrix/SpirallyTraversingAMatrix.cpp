#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
{
  vector<int>ans;
  int top=0,down=r-1,left=0,right=c-1;
  int dir=0;
  while(top<=down && left<=right)
  {
    if(dir==0)
    {
      for(int i=left;i<=right;i++)
        ans.push_back(matrix[top][i]);
      top++;
    }
    else if(dir==1)
    {
      for(int i=top;i<=down;i++)
        ans.push_back(matrix[i][right]);
      right--;
    }
    else if(dir==2)
    {
      for(int i=right;i>=left;i--)
        ans.push_back(matrix[down][i]);
      down--;
    }
    else if(dir==3)
    {
      for(int i=down;i>=top;i--)
        ans.push_back(matrix[i][left]);
      left++;
    }
    dir=(dir+1)%4;
  }
  return ans;
}

int main()
{
  int r,c;
  cin>>r>>c;
  vector<vector<int>>matrix(r);
  for(int i=0;i<r;i++)
  {
    vector<int>temp(c);
    for(int j=0;j<c;j++)
    {
      cin>>temp[j];
    }
    matrix[i]=temp;
  }
  vector<int>ans;
  ans=spirallyTraverse(matrix,r,c);
  for(auto e:ans)
  cout<<e<<" ";
}
