#include<bits/stdc++.h>
using namespace std;
set<string> v;
void permute(string s,int it,int n)
{
  if(it==n)
  {
    v.insert(s);
  }
  else
  {
    for(int i=it;i<=n;i++)
    {
      swap(s[it],s[i]);
      permute(s,it+1,n);
      swap(s[it],s[i]);
    }
  }
}

int main()
{
  string s;
  cin>>s;
  int n=s.length();
  permute(s,0,n-1);
  cout<<v.size()<<endl;
  for(auto e:v)
  cout<<e<<endl;
}
