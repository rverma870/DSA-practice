#include<bits/stdc++.h>
using namespace std;

int longestSubstrDitinctChars(string s)
{
  int n=s.length(), count=0,i=0,j=0;
  unordered_map<char,int>m;
  while(j<n)
  {
    if(m.find(s[j])==m.end() || (m.find(s[j])!=m.end() && m[s[j]]<i))
    {
      m[s[j]]=j;
      if(j-i+1>count)
      count=j-i+1;
      j++;
    }
    else
    {
      i=m[s[j]]+1;
      m[s[j]]=j;
      j++;
    }
  }
  return count;
}

int main()
{
  string s;
  cin>>s;
  cout<<longestSubstrDitinctChars(s);
}
