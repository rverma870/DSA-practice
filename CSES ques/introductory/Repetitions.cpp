#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  char temp=s[0];
  int count=1,tempcount=1;
  for(int i=1;i<s.length();i++)
  {
    (temp==s[i]) ? tempcount++ : tempcount=1;
    temp=s[i];
    if(tempcount>1 && tempcount>count)
    {
      count=tempcount;
    }
  }
  cout<<count;
}
