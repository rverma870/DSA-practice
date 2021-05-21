#include<bits/stdc++.h>
using namespace std;

int atoi(string s)
{
  if(s[0]==48 && s[1]!=0)
  return 256;
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

int isValid(string s)
{
  if(s[0]==48 && s[1]!=46)
  return 0;
  int dot_count=0;
  s=s+".";
  int n=s.length(),j=-1;
  for(int i=0;i<n;i++)
  {
    if(s[i]==46)
    {
      dot_count++;
      if(s.substr(j+1,i-(j+1))=="")
        return 0;
      int temp=atoi(s.substr(j+1,i-(j+1)));
      if(temp>255 || temp==-1)
      {
        return 0;
        break;
      }
      j=i;
    }
  }
  if(dot_count==4)
  return 1;
  else
  return 0;
}

int main()
{
  string s;
  cin>>s;
  cout<<isValid(s);
}
