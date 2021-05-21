#include<bits/stdc++.h>
using namespace std;

string remove(string s)
{
    string ans;

    int count=1;
    while(count!=0)
    {
      count=0;
      int n=s.length();
      if(s[0]!=s[1])
      ans.push_back(s[0]);
      int j=0;
      while(j<n-1)
      {
        j++;
        if(s[j]!=s[j-1] && s[j]!=s[j+1])
        ans.push_back(s[j]);
        else
        count++;
      }
      if(count!=0)
      {
        s=ans;
        ans="";
      }
    }
    return ans;
}

int main()
{
  string s;
  cin>>s;
  cout<<remove(s);
}
