#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> arr, int target)
{
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int ans=INT_MAX;
    for(int i=0;i<n-2;i++)
    {
        int j=i+1,k=n-1;
        while(j<k)
        {
            int temp_sum=arr[i]+arr[j]+arr[k];
            if(abs(target-temp_sum)<abs(target-ans))
            {
                ans=temp_sum;
            }
            if(temp_sum>target)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return ans;
}

int main()
{
  int n,target;
  cin>>n>>target;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<threeSumClosest(arr,target);
}
