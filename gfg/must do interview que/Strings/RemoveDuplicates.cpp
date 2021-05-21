#include<bits/stdc++.h>
using namespace std;

string removeDups(string s)
{
  set<char>st;
  int n=s.length();
  string str;
  for(int i=0;i<n;i++)
  {
    if(st.find(s[i])==st.end())
    {
      st.insert(s[i]);
      str.push_back(s[i]);
    }
  }
  return str;
}

int main()
{
  string s;
  cin>>s;
  cout<<removeDups(s);
}
