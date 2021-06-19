#include<bits/stdc++.h>
using namespace std;

int countBitsFlip(int a, int b)
{
  int temp=a^b;
  int count=0;
  while(temp!=0)
  {
    int mask = (temp & -temp);
    temp-=mask;
    count++;
  }
  return count;
}

int main()
{
  int a,b;
  cin>>a>>b;
  cout<<countBitsFlip(a,b);
}
