#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;

  int low,high,start=0,end=1;
  for(int i=1;i<s.length();i++)
  {
    //for odd cases abcdeedfg
    low=i-1;
    high=i;
    while(low>=0 && high<s.length() && s[low]==s[high])
    {
      if(high-low+1>end)
      {
        start=low;
        end=high-low+1;
      }
      low--;
      high++;
    }
    //for even cases  abcdedfg
    low=i-1;
    high=i+1;
    while(low>=0 && high<s.length() && s[low]==s[high])
    {
      if(high-low+1>end)
      {
        start=low;
        end=high-low+1;
      }
      low--;
      high++;
    }
  }
  cout<<s.substr(start,end);
}
