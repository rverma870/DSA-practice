#include<bits/stdc++.h>
using namespace std;

int minThrow(int N, int arr[])
{
  int board[31];
  memset(board,-1,sizeof(board));

  for(int i=0;i<N;i++)
  {
    int u=arr[2*i];
    int v=arr[2*i+1];
    board[u]=v;
  }

  vector<bool>vis(31,false);
  queue<pair<int,int>> q;//blocks or nodes , no of time dice throw to reach it;
  q.push({1,0});
  vis[1]=true;

  while(!q.empty())
  {
    pair<int,int>p = q.front();
    q.pop();
    if(p.first==30)
      return p.second;
    for(int i=p.first+1; i<=p.first+6 && i<=30 ;i++)
    {
      if(!vis[i])
      {
        vis[i]=true;
        if(board[i]==-1)
          q.push({i,p.second+1});
        else
          q.push({board[i],p.second+1});
      }
    }
  }
}

int main()
{
  int n;
  cin>>n;
  int arr[2*n];
  for(int i=0;i<2*n;i++)
  cin>>arr[i];
  cout<<minThrow(n,arr);
}
