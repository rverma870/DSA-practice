#include<bits/stdc++.h>
using namespace std ;

int visited[8][8] ;
int ans=0 ;
bool issafe( int r , int c )
{
  if(visited[r][c]==-1)
    return false;

  for( int i=0 ; i<c ; i++)
  {
    if(visited[r][i]==1)
    return false ;
  }
  for( int i=r-1 , j =c-1 ; i>=0 && j>=0 ; i--,j--)
  {
    if(visited[i][j]==1)
    return false ;
  }
  for( int i=r+1 , j =c-1 ; i<8 && j>=0; i++,j--)
  {
    if(visited[i][j]==1)
    return false ;
  }
  return true ;
}
void soln(int col)
{
  if(col==8)
  {
    ans++ ;
    return;
  }
  for( int i=0 ; i<8 ; i++)
  {
      if(issafe(i,col))
      {
        visited[i][col]=1 ;
        soln(col+1);
        visited[i][col]=0 ;
      }
  }
}

int main()
{
  char board[8][8] ;
  for( int i=0 ; i<8 ; i++)
  {
    for( int j=0 ; j<8 ; j++)
    {
        cin>>board[i][j] ;
        if(board[i][j]=='*')
          visited[i][j]=-1;
        else
          visited[i][j]=0 ;
    }
  }
  soln(0);
  cout<<ans<<endl;
}
