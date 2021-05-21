#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
int solve(string s,int i , int j ,bool istrue)
{
  if(i>j)
  return true;
  if(i==j)
  {
    if(istrue==true)
      return s[i]=='T';
    else
      return s[i]=='F';
  }
  string temp=to_string(i);
  temp.push_back(' ');
  temp.append(to_string(j));
  temp.push_back(' ');
  temp.append(to_string(istrue));
  if(mp.find(temp)!=mp.end())
    return mp[temp];
  int lT,lF,rT,rF,ans=0;
  for(int k=i+1;k<j;k+=2)
  {
    lT=solve(s,i,k-1,true);
    rT=solve(s,k+1,j,true);
    lF=solve(s,i,k-1,false);
    rF=solve(s,k+1,j,false);

    if(s[k]=='&')
    {
      if(istrue==true)
        ans=ans+lT*rT;
      else
        ans=ans+lT*rF+lF*rT+lF*rF;
    }
    else if(s[k]=='|')
    {
      if(istrue==true)
        ans=ans+lT*rT+lT*rF+lF*rT;
      else
        ans=ans+lF*rF;
    }
    else if(s[k]=='^')
    {
      if(istrue==true)
        ans=ans+lT*rF+lF*rT;
      else
        ans=ans+lT*rT+lF*rF;
    }
  }
  return mp[temp]=ans;
}

int main()
{
  int N;
  cin>>N;
  string s;
  cin>>s;
  cout<<solve(s,0,N-1,true);


}
