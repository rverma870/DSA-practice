#include<bits/stdc++.h>
using namespace std;

string lookandsay(int n)
{
  string s={"1"},temp="";
  int count=1;
  char no;
  for(int i=1;i<=n;i++)
  {
    no=s[0];
    temp="";
    for(int j=1;j<s.length();j++)
    {
      if(s[j]==s[j-1])
      {
        no=s[j-1];
        count++;
      }
      else
      {
        temp+=to_string(count)+no;
        count=1;
        no=s[j];
      }
    }
    temp+=to_string(count)+no;
    count=1;
    s=temp;
  }
  return s;
}

int main()
{
  int n;
  cin>>n;
  cout<<lookandsay(n);
}
