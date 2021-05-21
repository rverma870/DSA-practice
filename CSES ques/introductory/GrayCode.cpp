#include <bits/stdc++.h>
using namespace std ;
int n ;
void gray(int k ,string s , int r)
{
  if(n==k)
  {
    cout<<s<<endl;
    return ;
  }
  if(r==0)
  {
    gray(k+1,'0'+s,0) ;
    gray(k+1,'1'+s,1) ;
  }
  else
  {
    gray(k+1,'1'+s,0) ;
    gray(k+1,'0'+s,1) ;
  }
}

int main()
{
  cin>>n ;
  string temp="" ;
  gray(0,temp,0) ;
}
