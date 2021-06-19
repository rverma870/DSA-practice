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

int setBits(int n)
{
 int setbit , count=0;
 while(n!=0)
 {
     setbit=getFirstSetBit(n);
     count++;
     n = n - (1<<(setbit-1));
 }
 return count;
}

int main()
{
  int n;
  cin>>n;
  cout<<setBits(n);
}
