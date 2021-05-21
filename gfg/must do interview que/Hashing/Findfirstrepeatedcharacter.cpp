#include<bits/stdc++.h>
using namespace std;

string firstRepChar(string s)
{
  set<char>st;
  string ans;
  for(int i=0;i<s.length();i++)
  {
    if(st.find(s[i])==st.end())
    {
      st.insert(s[i]);
    }
    else
    {
      return ans=s[i];
    }
  }
  return "-1";
}

int main()
{
  string s;
  cin>>s;
  cout<<firstRepChar(s);
}
