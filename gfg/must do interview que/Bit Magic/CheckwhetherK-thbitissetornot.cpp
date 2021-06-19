#include<bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k)
{
  return n&(1<<k);
}

int main()
{
  int n,k;
  cin>>n>>k;
  cout<<checkKthBit(n,k);
}
