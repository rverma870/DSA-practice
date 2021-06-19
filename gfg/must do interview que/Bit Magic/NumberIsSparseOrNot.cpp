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

bool isSparse(int n)
{
  int setbit , ind=-1;
  while(n!=0)
  {
    setbit=getFirstSetBit(n);
    if(setbit-ind!=1)
    {
      ind=setbit;
      n = n - (1<<(setbit-1));
    }
    else
    return false;
  }
  return true;
}

int main()
{
  int n;
  cin>>n;
  cout<<isSparse(n);
}
