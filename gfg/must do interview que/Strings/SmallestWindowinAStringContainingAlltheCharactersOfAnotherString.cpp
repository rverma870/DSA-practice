#include<bits/stdc++.h>
using namespace std;

string smallestWindow (string s, string p)
{
  string ans;
  int Pmap[123]={0},Smap[123]={0};
  int n=s.length(),m=p.length();
  if(m>n)
  return "-1";

  for(int i=0;i<m;i++)
    Pmap[p[i]]+=1;

  int i=0,j=0,match_count=0,disire_count=m;
  while(true)
  {
    bool f1=false,f2=false;

    //aquire
    while(i<n && match_count<disire_count)
    {
      Smap[s[i]]+=1;
      if(Smap[s[i]]<=Pmap[s[i]])
        match_count++;
      i++;
      f1=true;
    }

    while(j<i && match_count==disire_count)
    {
      if(ans.length()==0 || i-j<ans.length())
        ans=s.substr(j,i-j);
      Smap[s[j]]-=1;
      if(Smap[s[j]]<Pmap[s[j]])
        match_count--;
      j++;
      f2=true;
    }

    if(f1==false && f2==false)
      break;
  }
  if(ans.length()==0)
  return "-1";
  return ans;
}

int main()
{
  string s,p;
  cin>>s>>p;
  cout<<smallestWindow(s,p);
}
