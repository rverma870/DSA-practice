#include<bits/stdc++.h>
using namespace std;

bool KmpSubStringcheck(string s1 ,string s2)//check weather s2 is substring of s1
{
  //creating pi array of s2
  int n=s1.length(), m=s2.length();
  int pi[m];
  pi[0]=0;
  for(int i=1;i<m;i++)
  {
    int l=pi[i-1];
    while(l>0 && s2[i]!=s2[l])
    {
      l=s2[l-1];
    }
    if(s2[i]==s2[l])
      l++;
    pi[i]=l;
  }
  int i=0,j=0;
  while(i<n && j<m)
  {
    if(s1[i]==s2[j])
    {
      i++;
      j++;
    }
    else
    {
      if(j>0)
      j=pi[j-1];
      else
      i++;
    }
  }
  if(j==m)
  return true;
  return false;
}

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  cout<<KmpSubStringcheck(s1,s2);
}
