#include<bits/stdc++.h>
using namespace std;

unsigned int getFirstSetBit(int n)
{
   unsigned int t=(n & -n);
   unsigned int ans=0;
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

int main()
{
  int n;
  cin>>n;
  cout<<getFirstSetBit(n);
}
