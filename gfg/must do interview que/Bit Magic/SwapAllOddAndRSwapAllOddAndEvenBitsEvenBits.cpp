#include<bits/stdc++.h>
using namespace std;

unsigned int swapBits(unsigned int n)
{
  unsigned int even = 0xAAAAAAAA;
  unsigned int odd = 0x55555555;
  even = n & even;
  odd = n & odd;
  even>>=1;
  odd<<=1;
  return even|odd;
}

int main()
{
  unsigned int n;
  cin>>n;
  cout<<swapBits(n);
}
