#include<bits/stdc++.h>
using namespace std;

int sum(int a , int b)
{
  int carry=a&b;
  int sum=a^b;

  while(carry!=0)
  {
    carry=carry<<1;
    int temp=sum;
    sum=sum^carry;
    carry=temp&carry;
  }
  return sum;
}

int main()
{
  int a,b;
  cin>>a>>b;
  cout<<sum(a,b);
}
