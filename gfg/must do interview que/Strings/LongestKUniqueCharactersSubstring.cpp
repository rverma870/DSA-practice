#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k)
{
  int a[26]={0},count_k=0,i=0,j=0,n=s.length(),ans=-1;

  while(j<n)
  {
    if(a[s[j]-97]==0)
      count_k++;
    a[s[j]-97]+=1;
    if(count_k==k && j-i+1>ans)
    {
      ans=j-i+1;
    }
      while(count_k>k)
      {
        a[s[i]-97]-=1;
        if(a[s[i]-97]==0)
          count_k--;
        i++;
      }
      j++;
    }
  return ans;
}

int main()
{
  string s;
  cin>>s;
  int k;
  cin>>k;
  cout<<longestKSubstr(s,k);
}
