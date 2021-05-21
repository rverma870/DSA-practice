#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s,l,r,ans;
  cin>>s;
  int a[26],oddcount=0;
  char c,temp;
  for(int i=0;i<26;i++)
    a[i]=0;
  for(int i=0;i<s.length();i++)
    a[int(s[i]-'A')]+=1;
  for(int i=0;i<26;i++)
  {
    if(a[i]%2==1)
    {
      oddcount+=1;
      c = i + 65;
      ans=c;
    }
  }
  if(oddcount>1)
  cout<<"NO SOLUTION"<<"\n";
  else if(oddcount<=1)
  {
    for(int i=0;i<26;i++)
    {
      temp=i+65;
      string t(a[i]/2,temp);
      ans=t+ans+t;
    }
    cout<<ans<<"\n";
  }
}
