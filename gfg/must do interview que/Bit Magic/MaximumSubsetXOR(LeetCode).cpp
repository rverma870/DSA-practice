#include<bits/stdc++.h>
using namespace std;

int maxSubarrayXOR(int arr[], int N)
{
  int max=0,mask=0;
  unordered_set<int>st;
  for(int i=31;i>=0;i--)
  {
    mask|=(1<<i);
    for(int j=0;j<N;j++)
      st.insert(mask & arr[j]);
    int candidate = max|(1<<i);
    for(auto e:st)
    {
      if(st.find(e^candidate)!=st.end())
      {
        max=candidate;
        break;
      }
    }
    st.clear();
  }
  return max;
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  cout<<maxSubarrayXOR(arr,n);
}
