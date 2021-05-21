#include<bits/stdc++.h>
using namespace std;

int findZeroes(int arr[], int n, int m)
{
    int countzero=0;
    int i=0,j=0,subarray=0;
    while(i<n && j<n)
    {

        if(countzero<=m)
        {
            subarray=max(subarray,j-i);
            if(arr[j]==0)
            countzero++;
            j++;
        }
        else
        {
            if(arr[i]==0)
            countzero--;
            i++;
        }
    }
    if(countzero>m)
    {
        while(i<n && countzero>m)
        {
            if(arr[i]==0)
            countzero--;
            i++;
        }
        cout<<1<<endl;
        return max(subarray,j-i);
    }
    else
    {
      cout<<2<<endl;
      return max(subarray,j-i);
    }

}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int m;
  cin>>m;
  cout<<findZeroes(arr,n,m);

}
