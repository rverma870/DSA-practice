#include<bits/stdc++.h>
using namespace std;

string reverseWords(string S)
{
  S=S+' ';
  string temp="",word="";
  int n=S.length();
  for(int i=0;i<n;i++)
  {

    if(S[i]=='.')
    {
      temp='.'+word+temp;
      word="";
    }
    else if(S[i]==' ')
      temp=word+temp;
    else
      word+=S[i];
  }
  return temp;
}

int main()
{
  string s;
  getline(cin,s);
  string ans;
  ans=reverseWords(s);
  cout<<ans;
}
