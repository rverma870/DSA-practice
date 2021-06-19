#include<bits/stdc++.h>
using namespace std;
int setKthBit(int N, int K)
{
    int mask= 1<<K ;
    return N | mask;
}
int main()
{
  int n,k;
  cin>>n>>k;
  cout<<setKthBit(n,k);
}
