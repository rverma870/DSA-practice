#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    unsigned long long n;
    cin>>n;
      unsigned long long range=1,nine=9,ans,temp=1,prev=1;
      long long i=1;
      while(true)
      {
        range=range+nine*i;
        nine*=10;
        i++;
        if(range>n)
         break ;
        prev=range ;
      }
    range=prev;
    i--;
    ans=(n-range)/i;
    for(int j=1;j<i;j++)
    {
      temp*=10;
    }
    unsigned long long num =ans+temp;
    int pos=(n-range)%i;
    string a = to_string(num) ;
    cout<<a[pos]<<endl;
  }
}
