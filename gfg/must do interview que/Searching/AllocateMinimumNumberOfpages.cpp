#include<bits/stdc++.h>
using namespace std;

int no_of_student(int arr[],int n,int page,int m)
{
  int student=1,total=0;
  for(int i=0;i<n;i++)
  {
    if(arr[i]<=page)
    {
      total+=arr[i];
      if(total>page)
      {
        student++;
        total=arr[i];
      }
    }
    else
    return m+1;
  }
  return student;
}

int findPages(int arr[], int n, int m)
{
  int sum=0,min_page=0;
  for(int i=0;i<n;i++)
  {
    sum+=arr[i];
    min_page=min(min_page,arr[i]);
  }
  int l=min_page,h=sum,mid,students,ans;
  while(l<=h)
  {
    mid=(l+h)/2;
    students=no_of_student(arr,n,mid,m);
    cout<<students<<" "<<mid<<endl;
    if(students<=m)
    {
      ans=mid;
      h=mid-1;
    }
    else
    {
      l=mid+1;
    }
  }
  return ans;
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
  cout<<findPages(arr,n,m);
}
