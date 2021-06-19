#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};

bool cmp(pair<int,int>a,pair<int,int>b)
{
  return a.second<b.second;
}

int maxChainLen(val p[],int n)
{
    pair<int,int>arr[n];
    int dp[n];
    for(int i=0;i<n;i++)
    {
         dp[i]=1;
         arr[i].first=p[i].first;
         arr[i].second=p[i].second;
    }
    sort(arr,arr+n,cmp);
    for(int i=1;i<n;i++)
    {
      for(int j=0;j<i;j++)
      {
        if(arr[i].first>arr[j].second && dp[i]<=dp[j])
        {
          dp[i]=dp[j]+1;
        }
      }
    }
    return *max_element(dp,dp+n);
}

int main()
{
	int n;
	cin>>n;
	val p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	cout<<maxChainLen(p,n)<<endl;
}
