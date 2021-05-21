#include<bits/stdc++.h>
using namespace std;

int atoi(string s)
{
  int x=0;
  bool b=false;
  if(s[0]==45)
    b=true;
  for(int i=1&&b;i<s.length();i++)
	{
		if(s[i]>=48 && s[i]<=57)
		{
      x=x*10+(s[i]-48);
		}
		else
		{
			return -1;
      break;
		}
	}
  if(b)
  return x*-1;
  return x;
}

int main()
{
  string s;
  cin>>s;
  cout<<atoi(s);
}
