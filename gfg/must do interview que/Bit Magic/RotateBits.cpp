#include<bits/stdc++.h>
using namespace std;

vector<int>rotate (int n, int d)
{
  d=d%16;
  vector<int>ans;
  ans.push_back( (65535) & (n << d)|(n>>(16 - d)));
  ans.push_back((n>>d)| ( (65535) & (n<<(16-d)) ) );
  return ans;
}

int main()
{
  int n,d;
  cin>>n>>d;
  for(auto e:rotate(n,d))
  cout<<e<<" ";
}
