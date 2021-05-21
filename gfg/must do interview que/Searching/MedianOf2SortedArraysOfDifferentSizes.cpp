#include<bits/stdc++.h>
using namespace std;

int kth_element(auto a1, auto a2, auto end1, auto end2, int k)
{
  if(a1==end1)
  return a2[k];
  if(a2==end2)
  return a1[k];
  int mid1=(end1-a1)/2,mid2=(end2-a2)/2;
  if(mid1+mid2<k)
  {
    if(a1[mid1]>a2[mid2])
    return kth_element(a1,a2+mid2+1,end1,end2,k-mid2-1);
    else
    return kth_element(a1+mid1+1,a2,end1,end2,k-mid1-1);
  }
  else
  {
    if(a1[mid1]>a2[mid2])
    return kth_element(a1, a2, a1+mid1, end2, k);
    else
    return kth_element(a1, a2, end1, a2+mid2, k);
  }
}

double MedianOfArrays(vector<int>& array1, vector<int>& array2)
{
  int m=array1.size(),n=array2.size();
  if((m+n)%2==0)
  {
    int median=(m+n)/2;
    int x=kth_element(array1.begin(), array2.begin(), array1.begin()+m, array2.begin()+n, median-1);
    int y=kth_element(array1.begin(), array2.begin(), array1.begin()+m, array2.begin()+n, median);
    return (double)(x+y)/2;
  }
  else
  return kth_element(array1.begin(), array2.begin(), array1.begin()+m, array2.begin()+n,(m+n+1)/2-1);
}

int main()
{
  int m;
  cin>>m;
  vector<int>array1(m);
  for(int i=0;i<m;i++)
    cin>>array1[i];
  int n;
  cin>>n;
  vector<int>array2(n);
  for(int i=0;i<n;i++)
    cin>>array2[i];
  cout<<MedianOfArrays(array1,array2);
}
