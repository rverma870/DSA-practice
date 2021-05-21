#include<bits/stdc++.h>
using namespace std;

int lps(string s)
{
  int n=s.length();
  int pi[n];
  pi[0]=0;
  int l=0;
  for(int i=1;i<n;i++)
  {
      l=pi[i-1];

      while(l>0 && s[i]!=s[l])
      {
          l=pi[l-1];
      }
      if(s[i]==s[l])
      l++;
      pi[i]=l;
  }
  return pi[n-1];
}

int main()
{
  string s;
  cin>>s;
  cout<<lps(s);
}
