#include<bits/stdc++.h>
using namespace std;

vector<string>permut(string s,int start,int n,vector<string> &ans)
{
  if(start==n)
  {
    ans.push_back(s);
  }
  for(int i=start;i<n;i++)
  {
    swap(s[start],s[i]);
    permut(s,start+1,n,ans);
    swap(s[start],s[i]);
  }
  return ans;
}

vector<string>find_permutation(string s)
{
  int n=s.length();
  vector<string>ans;
  permut(s,0,n,ans);
  sort(ans.begin(),ans.end());
  return ans;
}

int main()
{
  string s;
  cin>>s;
  vector<string>ans;
  ans=find_permutation(s);
  for(auto e:ans)
  cout<<e<<", ";
}
