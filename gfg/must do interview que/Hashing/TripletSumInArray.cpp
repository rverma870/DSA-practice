#include<bits/stdc++.h>
using namespace std;

bool find3Numbers(int a[], int n, int x)
{
sort(a,a+n);
  for(int i=0;i<n;i++)
  {
    int j=i+1,k=n-1,sum=x-a[i];
    while(j<k)
    {
      int temp=a[j]+a[k];
      if(temp==sum)
        return true;
      else if(temp<sum)
        j++;
      else
        k--;
    }
  }
  return false;
}

int main()
{
  int n,x;
  cin>>n>>x;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  cout<<find3Numbers(a,n,x);
}
