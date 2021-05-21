#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  set<int> s;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    auto it = s.find(temp-1);
    if(it!=s.end())
    s.erase(it) ;
    s.insert(temp) ;
  }
  cout<<s.size();

}
