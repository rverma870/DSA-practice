#include<bits/stdc++.h>
using namespace std;

struct Point
{
  int x;
  int y;
};

struct queueNode
{
  Point pt;
  int dist;
};

bool isValid(int row, int col ,int n,int m)
{
  return (row >= 0) && (row < n) && (col >= 0) && (col < m);
}

int BFS(vector<vector<int>>mat, Point src, Point dest)
{
  int rowNum[] = {-1, 0, 0, 1};
  int colNum[] = {0, -1, 1, 0};
  int ROW=mat.size();
  int COL=mat[0].size();

  if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
      return -1;

  bool visited[ROW][COL];
  memset(visited, false, sizeof visited);

  visited[src.x][src.y] = true;

  queue<queueNode> q;

  queueNode s = {src, 0};
  q.push(s);

  while (!q.empty())
  {
    queueNode curr = q.front();
    Point pt = curr.pt;

    if (pt.x == dest.x && pt.y == dest.y)
        return curr.dist;

    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int row = pt.x + rowNum[i];
      int col = pt.y + colNum[i];

      if (isValid(row, col,ROW,COL) && mat[row][col] && !visited[row][col])
      {
          visited[row][col] = true;
          queueNode Adjcell = { {row, col}, curr.dist + 1 };
          q.push(Adjcell);
      }
    }
  }
  return -1;
}

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
{
  Point source = {0, 0};
  Point dest = {X, Y};

   int dist = BFS(A, source, dest);
   return dist;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>>graph(n);
  for(int i=0;i<n;i++)
  {
    vector<int>temp(m);
    for(int j=0;j<m;j++)
      cin>>temp[j];
    graph[i]=temp;
  }
  int x,y;
  cin>>x>>y;
  cout<<shortestDistance(n,m,graph,x,y);
}
