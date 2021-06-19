#include<bits/stdc++.h>
using namespace std;

long long reversedBits(long long n)
{
    long long ans=0;
    if(n==0)
    return ans;
    string binaryNum="";
    int i = 0;
    while (n > 0)
    {
        binaryNum+=to_string(n % 2);
        n = n / 2;
        i++;
    }
    reverse(binaryNum.begin(),binaryNum.end());
    binaryNum="00000000000000000000000000000000" + binaryNum;
    reverse(binaryNum.begin(),binaryNum.end());
    string s=binaryNum.substr(0,32);
    long long base=1;

    for(int j=s.length()-1;j>=0;j--)
    {
      int last_digit = int(s[j]-'0');
      ans += last_digit * base;
      base = base * 2;
    }
    return ans;
}
int main()
{
  long long n;
  cin>>n;
  cout<<reversedBits(n);
}
