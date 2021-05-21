#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  map<string,string> NC;
  map<string,int>name;
  map<string,int>country;
  for(int i=0;i<n;i++)
  {
    string a,b;
    cin>>a>>b;
    NC[a]=b;
    name[a]=0;
    country[b]=0;
  }
  string winname,wincountry;
  for(int i=0;i<m;i++)
  {
    string vote;
    cin>>vote;
    name[vote]+=1;
    country[NC[vote]]+=1;
  }
  int v=0 ;
  for(auto e:name)
  {
    if(e.second>v)
    {
      winname=e.first;
      v=e.second;
    }
  }
  v=0;
  for(auto e:country)
  {
    if(e.second>v)
    {
      wincountry=e.first;
      v=e.second;
    }
  }
  cout<<wincountry<<endl<<winname<<endl;

}
