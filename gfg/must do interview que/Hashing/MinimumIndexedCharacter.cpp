#include<bits/stdc++.h>
using namespace std;

int minIndexChar(string str, string patt)
{
  unordered_map<char,int>mp;
  int ans=INT_MAX;
  for(int i=1;i<=str.length();i++)
  {
    if(mp[str[i-1]]==0)
      mp[str[i-1]]=i;
  }
  for(int i=0;i<patt.length();i++)
  {
    if(mp[patt[i]]!=0 && mp[patt[i]]<ans)
    {
      ans=mp[patt[i]];
    }
  }
  return ans-1;
}
int main()
{
  string s,patt;
  cin>>s>>patt;
  cout<<minIndexChar(s,patt);

}
