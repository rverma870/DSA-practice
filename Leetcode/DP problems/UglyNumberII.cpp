#include<bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
    set<long long>possibleno,fix;
    possibleno.insert(1);
    while(fix.size()!=n)
    {
        long long nextugly=*possibleno.begin();
        fix.insert(nextugly);
        possibleno.erase(nextugly);
        possibleno.insert(2*nextugly);
        possibleno.insert(3*nextugly);
        possibleno.insert(5*nextugly);
    }
    return *fix.rbegin();
}

int main()
{
  int n;
  cin>>n;
  cout<<nthUglyNumber(n)<<endl;

}
