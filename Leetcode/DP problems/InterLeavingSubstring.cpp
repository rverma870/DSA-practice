#include<bits/stdc++.h>
using namespace std;
bool check(int p1,int p2,int p3,string s1,string s2,string s3,int l1,int l2,int l3,unordered_map<string,bool> dp)
{
  if(p3==l3)
   return (p1==l1 && p2==l2)?true:false;

  string key=to_string(p1)+'*'+to_string(p2)+'*'+to_string(p3);
  if(dp.find(key)!=dp.end())
    return dp[key];

  if(p1==l1)
    return dp[key]=(s2[p2]==s3[p3])?check(p1,p2+1,p3+1,s1,s2,s3,l1,l2,l3,dp):false;
  if(p2==l2)
    return dp[key]=(s1[p2]==s3[p3])?check(p1+1,p2,p3+1,s1,s2,s3,l1,l2,l3,dp):false;

  bool one=false,two=false;
  if(s1[p1]==s3[p3])
    one=check(p1+1,p2,p3+1,s1,s2,s3,l1,l2,l3,dp);
  if(s2[p2]==s3[p3])
    two=check(p1,p2+1,p3+1,s1,s2,s3,l1,l2,l3,dp);
  return dp[key]=one || two;
}
int main()
{
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  int l1,l2,l3;
  l1=s1.length();
  l2=s2.length();
  l3=s3.length();
  unordered_map<string,bool>dp;
  if(l1+l2!=l3)
    return false;
  cout<<check(0,0,0,s1,s2,s3,l1,l2,l3,dp);
}
