#include<bits/stdc++.h>
using namespace std;

int canRepresentBST(int arr[], int N)
{
  stack<int>stk;
  stk.push(arr[0]);
  int parent=INT_MIN;
  for(int i=1;i<N;i++)
  {
    while(!stk.empty() && stk.top() < arr[i] )
    {
      parent=stk.top();
      stk.pop();
    }
    if(arr[i] < parent)
    return false;
    stk.push(arr[i]);
  }
  return true;
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<canRepresentBST(arr,n);
}
