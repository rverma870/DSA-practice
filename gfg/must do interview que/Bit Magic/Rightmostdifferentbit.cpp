#include<bits/stdc++.h>
using namespace std;

int posOfRightMostDiffBit(int m, int n)
{
    int temp=max(m,n) - min(m,n);
    int mask = temp & -temp;
    int ans=0;
    if(mask==0)
     return -1;
    while(mask > 1)
    {
       mask/=2;
       ans++;
    }
     return ans+1;
}

int main()
{
  int n,m;
  cin>>n>>m;
  cout<<posOfRightMostDiffBit(n,m);
}
