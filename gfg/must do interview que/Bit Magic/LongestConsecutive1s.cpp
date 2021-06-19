#include<bits/stdc++.h>
using namespace std;

int getFirstSetBit(int n)
{
   int t=(n & -n);
   int ans=0;
   if(t==0)
    return 0;
   else
   {
     while(t/2>0)
     {
       t/=2;
       ans++;
     }
     return ans+1;
   }
}

int maxConsecutiveOnes(int n)
{
  int ans=0, prepos=-1, curpos=-1, count=0;
  curpos=getFirstSetBit(n);
  if(curpos!=0)
  {
    prepos=curpos;
    n = n - (1<<(curpos-1));
    ans=1;
    count=1;
  }
  while(n!=0)
  {
    curpos=getFirstSetBit(n);
    if(curpos-prepos==1)
    {
      count++;
      ans=max(ans,count);
      prepos=curpos;
      n = n- (1<<(curpos-1));
    }
    else
    {
      count=1;
      prepos=curpos;
      n = n- (1<<(curpos-1));
    }
  }
  return ans;
}
int main()
{
  int n;
  cin>>n;
  cout<<maxConsecutiveOnes(n);
}
