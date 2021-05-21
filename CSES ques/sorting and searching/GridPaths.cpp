#include<bits/stdc++.h>
using namespace std;
string s;
bool a[7][7];
int ans;
bool isvalid(int r , int c)
{
  if(a[r][c])
    return false ;
  else if( r<0 or r>6)
    return false ;
  else if( c<0 or c>6)
    return false ;
  return true ;
}

void solve(int r, int c, int i)
{
    if(r==6 && c==0)
    {
      if(i==48)
        ans++;
      return;
    }
    a[r][c]=true ;

    if(s[i]=='L' or s[i]=='?')
    {
      if(c>0 and isvalid(r,c-1))
        if(!(!(isvalid(r,c-2)) and isvalid(r-1,c-1) and isvalid(r+1,c-1) )) //up left down
          solve(r,c-1,i+1);//left
    }

    if(s[i]=='R' or s[i]=='?')
    {
    //  cout<<"Rightcall\n" ;
      if(c<6 and isvalid(r,c+1))
        if(!(!(isvalid(r,c+2)) and isvalid(r-1,c+1) and isvalid(r+1,c+1) ))// up right down
            solve(r,c+1,i+1);//right
    }
    if(s[i]=='U' or s[i]=='?' )
    {
      if(r>0 and isvalid(r-1,c))
        if(!( !(isvalid(r-2,c)) and  isvalid(r-1,c-1) and isvalid(r-1,c+1) ) )// left up right
          solve(r-1,c,i+1);//up
    }

    if(s[i]=='D' or s[i]=='?' )
    {
      if(r<6 and isvalid(r+1,c))
        if(!(!(isvalid(r+2,c)) and isvalid(r+1,c-1)  and isvalid(r+1,c+1)))//left down right
          solve(r+1,c,i+1);//down
    }
    a[r][c] = false ;

}
int main()
{
  cin>>s;
  memset(a,false,sizeof(a));
  ans=0;
  solve(0,0,0);
  cout<<ans;
}
