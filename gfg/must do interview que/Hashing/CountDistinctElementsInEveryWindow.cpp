#include<bits/stdc++.h>
using namespace std;

vector <int> countDistinct (int a[], int n, int k)
{
  unordered_map<int,int>mp;
  vector<int>ans;
  int count=0;
  for(int i=0;i<k;i++)
  {
    if(mp[a[i]]==0)
    count++;
    mp[a[i]]+=1;
  }
  ans.push_back(count);
  int i=0,j=k;
  while(j<n)
  {
    if(mp[a[j]]==0)
      count++;
    mp[a[j]]+=1;
    mp[a[i]]-=1;
    if(mp[a[i]]==0)
      count--;
    ans.push_back(count);
    j++;
    i++;
  }
  return ans;  
}

int main()
{
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  vector<int>ans;
  ans=countDistinct(a,n,k);
  for(auto e:ans)
  cout<<e<<" ";
}
