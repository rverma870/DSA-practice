#include<bits/stdc++.h>
using namespace std;

vector<int> kthLargest(int k, int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(q.size()<=k)
        q.push(arr[i]);

        if(q.size()==k)
            ans.push_back(q.top());
        else if(q.size()>k)
        {
            q.pop();
            ans.push_back(q.top());
        }
        else
            ans.push_back(-1);
    }
    return ans;
}

int main()
{
  int k,n;
  cin>>k>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  for(auto e : kthLargest(k,arr,n))
    cout<<e<<" ";
}
