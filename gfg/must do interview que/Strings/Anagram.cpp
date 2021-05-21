#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b)
{
  int n=a.length(),m=b.length();
  multiset<char>s;
  for(int i=0;i<n;i++)
  s.insert(a[i]);
  for(int i=0;i<m;i++)
  {
    auto it=s.find(b[i]);
    if(it!=s.end())
      s.erase(it);
    else
      return false;
  }
  if(s.empty())
  return true;
}

int main()
{
  string a,b;
  cin>>a>>b;
  cout<<isAnagram(a,b);

}
