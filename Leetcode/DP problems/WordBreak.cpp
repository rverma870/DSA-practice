#include <bits/stdc++.h>
using namespace std;

int solve(string s,set<string>word_set,int n)
{
  int dp[n];
  memset(dp,0,sizeof(dp));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<=i;j++)
    {
      if(dp[i] >= 1)
        break ;
      if(word_set.find(s.substr(j,i-j+1))!=word_set.end())
      {
        if(j>0)
        dp[i]=dp[j-1];
        else
        dp[i]=1;
      }
    }
  }
  return dp[n-1]>0;
}

bool wordBreak(string s, vector<string>& wordDict)
{
    set<string> word_set(wordDict.begin(), wordDict.end());
    int n=s.length();
    return solve(s,word_set,n);
}


int main()
{
  string s;
  cin>>s;
  vector<string> wordDict;
  // wordDict.push_back("aaaa");
  // wordDict.push_back("aaa");
  // // wordDict.push_back("sand");
  // // wordDict.push_back("and");
  // // wordDict.push_back("cat");
  string test = "a" ;
  for(int i=1;i<=10;i++)
  {
    wordDict.push_back(test);
    test += "a" ;
  }
  cout<<wordBreak(s,wordDict);
}
