#include<bits/stdc++.h>
using namespace std;

bool valid(int i,int j,int n,int m)
{
  if(i>=0 && i<n && j>=0 && j<m)
    return true;
  return false;
}
int orangesRotting(vector<vector<int>>& grid)
{
   queue<pair<int , pair<int,int>>>q;
   int n=grid.size();
   int m=grid[0].size();
   int count=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(grid[i][j]==2)
             q.push(make_pair(0 , make_pair(i,j)));
           if(grid[i][j]==1)
              count++;
       }
   }
   int ans=0;
   while(!q.empty())
   {
       int i=q.front().second.first;
       int j=q.front().second.second;
       if(valid(i-1,j,n,m))
       {
         if(grid[i-1][j]==1)
         {
           grid[i-1][j]=2;
            q.push(make_pair(q.front().first+1,make_pair(i-1,j)));
            count--;
         }
       }
       if(valid(i+1,j,n,m))
       {
         if(grid[i+1][j]==1)
        {
          grid[i+1][j]=2;
          q.push(make_pair(q.front().first+1,make_pair(i+1,j)));
          count--;
        }
       }
       if(valid(i,j-1,n,m))
       {
         if(grid[i][j-1]==1)
         {
           grid[i][j-1]=2;
           q.push(make_pair(q.front().first+1,make_pair(i,j-1)));
           count--;
         }
       }
       if(valid(i,j+1,n,m))
       {
         if(grid[i][j+1]==1)
        {
          grid[i][j+1]=2;
          q.push(make_pair(q.front().first+1,make_pair(i,j+1)));
          count--;
        }
       }
       ans=q.front().first;
       q.pop();
   }
   if(count!=0)
    return -1;
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
  cout<<orangesRotting(matrix);
}
