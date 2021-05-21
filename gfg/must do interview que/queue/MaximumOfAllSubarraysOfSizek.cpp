#include<bits/stdc++.h>
using namespace std;

vector <int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int>ans;
    deque<int>q;
    int j=0;
    while(j<k)
    {
      if(q.empty())
      {
        q.push_front(arr[j]);
        j++;
      }
      else
      {
        while(arr[j]>q.back())
        {
          q.pop_back();
          if(q.empty())
            break;
        }
        q.push_back(arr[j]);
        j++;
      }
    }
    ans.push_back(q.front());
    int i=0;
    while(j<n)
    {
      while(q.back()<arr[j])
      {
        q.pop_back();
        if(q.empty())
          break;
      }
      q.push_back(arr[j]);
      if(arr[i]==q.front())
        q.pop_front();
      ans.push_back(q.front());
      i++;
      j++;
    }
    return ans;
}

int main()
{
  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  for(auto e:max_of_subarrays(arr,n,k))
      cout<<e<<" ";
}
