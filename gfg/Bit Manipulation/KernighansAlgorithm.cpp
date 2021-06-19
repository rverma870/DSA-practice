#include<bits/stdc++.h>
using namespace std;
//This algorithm is used for calculating no of set bits in a number;
int CountSetBit(int n)
{
  int count=0;
  while(n!=0)
  {
    int mask = (n & -n);
    n-=mask;
    count++;
  }
  return count;
}
int main()
{
  int n;
  cin>>n;
  cout<<CountSetBit(n);
}
