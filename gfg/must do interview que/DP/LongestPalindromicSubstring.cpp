#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string S)
{
  int low,high,start=0,end=1;
  for(int i=1;i<S.length();i++)
  {
    //for odd cases abcdeedfg
    low=i-1;
    high=i;
    while(low>=0 && high<S.length() && S[low]==S[high])
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
    while(low>=0 && high<S.length() && S[low]==S[high])
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
  return S.substr(start,end);
}

int main()
{
  string S;
  cin>>S;
  cout<<longestPalindrome(S);
}
