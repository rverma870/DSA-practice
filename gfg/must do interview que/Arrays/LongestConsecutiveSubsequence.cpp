#include<bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
  map<int,int>m;
  int ans=1;
  for(int i=0;i<N;i++)
      m[arr[i]]=1;

  for(auto e:m)
  {
      if(m.find(e.first-1)!=m.end())
      {
          m[e.first]=m[e.first-1]+1;
      }
  }
  for(auto e:m)
  ans=max(ans,e.second);
  return ans;
}

int main()
{
  int N;
  cin>>N;
  int arr[N];
  for(int i=0;i<N;i++)
    cin>>arr[i];
  cout<<findLongestConseqSubseq(arr,N);
}
