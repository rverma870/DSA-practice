#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string s)
{
  deque<char>q;
  string ans="";
  int mp[26]={0};
  for(int i=0;i<s.length();i++)
  {
    mp[s[i]-97]+=1;
    if(q.empty() && mp[s[i]-97]==1)
      q.push_back(s[i]);
    else if(mp[s[i]-97]==1)
      q.push_back(s[i]);
    while(!q.empty() && mp[q.front()-97]>1)
    {
      q.pop_front();
      if(q.empty())
        break;
    }
    if(q.empty())
    ans+='#';
    else
    ans+=q.front();
  }
  return ans;
}

int main()
{
  string s;
  cin>>s;
  cout<<FirstNonRepeating(s);
}
