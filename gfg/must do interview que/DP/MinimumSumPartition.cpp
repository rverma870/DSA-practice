#include <bits/stdc++.h>
using namespace std;

int minDiffernce(int arr[], int n)
{
  int sum=0;
  for(int i=0;i<n;i++)
  sum+=arr[i];
  int ans=sum;
  bool t[n+1][sum+1];
  for(int i=0;i<n+1;i<i++)
  t[i][0]=true;
  for(int i=1;i<sum+1;i++)
  t[0][i]=false;

  for(int i=1;i<n+1;i++)
  {
      for(int j=1;j<sum+1;j++)
      {
          if(arr[i-1]<=j)
          t[i][j]= t[i-1][j-arr[i-1]] or t[i-1][j];
          else
          t[i][j]=t[i-1][j];
      }
  }
  for(int i=0;i<sum+1;i++)
  {
    if(t[n][i])
    {
        ans=min(ans,abs(2*i-sum));
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++)
  	cin >> a[i];
  cout<<minDiffernce(a, n) << "\n";
}
