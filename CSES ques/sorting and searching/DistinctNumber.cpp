#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,count=1,temp;
  cin>>n;
  long long a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  sort(a,a+n);
  temp=a[0];
  for(int i=0;i<n;i++)
  {
    if(a[i]==temp)
    continue;
    else
    {
      temp=a[i];
      count++;
    }
  }
  cout<<count<<endl;
}
