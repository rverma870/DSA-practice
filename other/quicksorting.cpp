#include<bits/stdc++.h>
using namespace std;

int partion(int A[],int l,int u)
{
  int pivot=A[l],start=l,end=u;
  while(start<end)
  {
    while(A[start]<=pivot)
      start++;
    while(A[end]>pivot)
      end--;
    if(start<end)
      swap(A[start],A[end]);
  }
  swap(A[l],A[end]);
    return end;
}
void quicksort(int A[],int l,int u)
{
  int loc;
  if (l<u)
  {
     loc=partion(A,l,u);
     quicksort(A,l,loc-1);
     quicksort(A,loc+1,u);
  }
}
int main()
{
  int A[5]={3,2,1,5,4};
  quicksort(A,0,4);
  for(int i=0;i<5;i++)
    cout<<A[i]<<" ";
  return 0;
}
