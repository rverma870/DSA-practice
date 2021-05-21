#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix (string arr[], int n)
{
  string s,lon_str;
  int len=0;
  for(int i=0;i<n;i++)
  {
    s=arr[i];
    if(s.length()>len)
    {
      len=s.length();
      lon_str=s;
    }
  }
  s="";
  for(int i=0;i<n;i++)
  {
    int templen=0;
    for(int j=0;j<arr[i].length();j++)
    {
      if(arr[i][j]==lon_str[j])
      {
        templen++;
      }
      else
      {
        if(templen<len)
        {
          len=templen;
          s=lon_str.substr(0,len);
        }
        break;
      }
    }
  }
  if(s.length()>0)
   return s;
  else
   return s="-1";
}

int main()
{
  int n;
  cin>>n;
  string arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  cout<<longestCommonPrefix(arr,n);
}
