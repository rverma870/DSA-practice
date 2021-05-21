#include<bits/stdc++.h>
using namespace std;

long long kthSmallest(long long k, long long arr[], long long n)
{
    if(k>n)
    return LLONG_MAX;
    priority_queue<long long> q;
    for(long long i=0;i<n;i++)
    {
      if(q.size()<=k)
        q.push(arr[i]);
      if(q.size()>k)
        q.pop();
    }
    return q.top();
}
long long sumBetweenTwoKth( long long a[], long long n, long long k1, long long k2)
{
   long long first = kthSmallest(k1,a,n) , second = kthSmallest(k2,a,n),ans=0;
   for(long long i=0;i<n;i++)
   {
     if(a[i]>first && a[i]<second)
      ans+=a[i];
   }
   return ans;
}
int main()
{
  long long n;
  cin>>n;
  long long arr[n];
  for(long long i=0;i<n;i++)
    cin>>arr[i];
  long long k1,k2;
  cin>>k1>>k2;
  cout<<sumBetweenTwoKth(arr,n,k1,k2);
}
