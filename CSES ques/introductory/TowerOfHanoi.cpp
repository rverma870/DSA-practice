#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> mov ;
void solve(int s,int d,int h,int n)
{
  if(n==1)
  {
     mov.push_back(make_pair(s,d)) ;
     return;
  }
  solve(s,h,d,n-1);
  mov.push_back(make_pair(s,d)) ;
  solve(h,d,s,n-1);
}

int main()
{
  int n;
  cin>>n;
  solve(1,3,2,n);
  cout<<mov.size()<<"\n" ;
  for(auto x: mov)
    cout<<x.first<<" "<<x.second<<"\n" ;
}
