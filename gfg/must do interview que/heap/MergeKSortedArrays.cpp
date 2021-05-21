#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
   priority_queue<int,vector<int>,greater<int>>q;
   for(int i=0;i<K;i++)
   {
       for(int j=0;j<K;j++)
        q.push(arr[i][j]);
   }
   vector<int>ans;
   while(!q.empty())
   {
       ans.push_back(q.top());
       q.pop();
   }
   return  ans;
}

int main()
{
  int n;
  cin>>n;
  vector<vector<int>> arr(n);
  for(int i=0;i<n;i++)
  {
    vector<int>temp(n);
    for(int j=0;j<n;j++)
    cin>>temp[j];
    arr[i]=temp;
  }
  for(auto e: mergeKArrays(arr,n))
  cout<<e<<" ";
}
