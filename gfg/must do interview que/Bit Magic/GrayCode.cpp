#include<bits/stdc++.h>
using namespace std;

vector<string> graycode(int n)
{
    if(n==1)
    {
        vector<string>temp;
        temp.push_back("0");
        temp.push_back("1");
        return temp;
    }
    vector<string>rres=graycode(n-1);
    vector<string>ans;
    for(int i=0;i<rres.size();i++)
    {
        ans.push_back("0" + rres[i]);
    }
    for(int i=rres.size()-1; i>=0; i--)
    {
        ans.push_back( "1" + rres[i]);
    }
    return ans;
}

int main()
{
  int n;
  cin>>n;
  for(auto e:graycode(n))
  cout<<e<<" ";
}
