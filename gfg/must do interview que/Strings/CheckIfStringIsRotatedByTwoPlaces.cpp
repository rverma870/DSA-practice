#include<bits/stdc++.h>
using namespace std;

bool isRotated(string str1, string str2)
{
  int n=str1.length();
  if(str2.length()!=n)
  return false;
  if(n<3)
  return str1==str2;
  //anticlockwise

  string temp="";
  temp+=str1.substr(0,2);
  temp=str1.substr(2)+temp;
  if(temp==str2)
  return true;

  //clockwise

  temp="";
  temp+=str1.substr(n-2);
  temp=temp+str1.substr(0,n-2);
  if(temp==str2)
  return true;

  return false;
}

int main()
{
  string str1,str2;
  cin>>str1>>str2;
  cout<<isRotated(str1,str2);
}
