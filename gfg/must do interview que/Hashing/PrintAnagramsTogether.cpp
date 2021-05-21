#include<bits/stdc++.h>
using namespace std;

vector<vector<string> > Anagrams(vector<string>& string_list)
{
  map<string,vector<int>>mp;
  int n=string_list.size();
  vector<vector<string>>ans;
  string temp;
  for(int i=0;i<n;i++)
  {
    temp=string_list[i];
    sort(temp.begin(),temp.end());
    mp[temp].push_back(i);
  }
  for(auto e:mp)
  {
    vector<string>t;
    for(auto f:e.second)
    {
      t.push_back(string_list[f]);
    }
    ans.push_back(t);
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  vector<string>v(n);
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    v[i]=s;
  }
  vector<vector<string>>ans;
  ans=Anagrams(v);
  for(int i=0;i<ans.size();i++)
  {
    for(int j=0;j<ans[i].size();j++)
    cout<<ans[i][j]<<" ";
    cout<<endl;
  }
}
