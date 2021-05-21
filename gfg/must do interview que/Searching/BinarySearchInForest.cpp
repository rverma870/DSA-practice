#include<bits/stdc++.h>
using namespace std;

int wood_collect(int tree[],int n,int height)
{
  int sum=0;
  for(int i=n-1;i>=0;i--)
  {
    if(tree[i]-height<0)
    break;
    sum+=tree[i]-height;
  }
  return sum;
}

int find_height(int tree[], int n, int k)
{
  sort(tree,tree+n);
  int l=0,h=tree[n-1],mid;
  while(l<=h)
  {
    mid=(h+l)/2;
    int collected_wood=wood_collect(tree,n,mid);
    if(collected_wood<k)
    h=mid-1;
    else if(collected_wood>k)
    l=mid+1;
    else
    return mid;
  }
  return -1;
}
int main()
{
  int n,k;
  cin>>n>>k;
  int tree[n];
  for(int i=0;i<n;i++)
  cin>>tree[i];
  cout<<find_height(tree,n,k);
}
