#include<bits/stdc++.h>
using namespace std;

int triplet_before_k(int arr[],int n,int k)
{
  sort(arr,arr+n);
  int count=0,sum;
  for(int i=0;i<n-2;i++)
  {
    int l=i+1,h=n-1;
    while(l<h)
    {
      sum=arr[i]+arr[l]+arr[h];
      if(sum>k)
      h--;
      else
      {
        count+=h-l;
        l++;
      }
    }
  }
  return count;
}

int countTriplets(int Arr[], int N, int L, int R)
{
  return (triplet_before_k(Arr,N,R)-triplet_before_k(Arr,N,L-1));
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  int L,R;
  cin>>L>>R;
  cout<<countTriplets(arr,n,L,R);
}
