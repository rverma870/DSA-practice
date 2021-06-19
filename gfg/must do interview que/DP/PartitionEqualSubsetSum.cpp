#include <bits/stdc++.h>
using namespace std;

int equalPartition(int N, int arr[])
{
  int sum=0;
  for(int i=0;i<N;i++)
  sum+=arr[i];

  if(sum & 1==1)
  return 0;
  else
  {
    sum=sum/2;
    bool t[N+1][sum+1];
    for(int i=0;i<N+1;i++)
    t[i][0]=true;
    for(int i=1;i<sum+1;i++)
    t[0][i]=false;
    for(int i=1;i<N+1;i++)
    {
      for(int j=1;j<sum+1;j++)
      {
          if(arr[i-1]<=j)
          t[i][j]=  t[i-1][j-arr[i-1]] or t[i-1][j] ;
          else
          t[i][j]= t[i-1][j];
      }
    }
    return t[N][sum];
  }
}

int main()
{
  int N;
  cin>>N;
  int arr[N];
  for(int i = 0;i < N;i++)
      cin>>arr[i];
  if(equalPartition(N, arr))
      cout<<"YES\n";
  else
      cout<<"NO\n";

}
