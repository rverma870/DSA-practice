#include<bits/stdc++.h>
using namespace std;

pair<long,long> indexes(vector<long long> v, long long x)
{
  pair<long,long>ans;
  int i=lower_bound(v.begin(),v.end(),x)-v.begin();
  int j=upper_bound(v.begin(),v.end(),x)-v.begin();

  if(v[i]==x && v[j-1]==x)
  {
    return ans=make_pair(i,j-1);
  }
  else
  return ans=make_pair(-1,-1);
}


int main()
{
  int n;
  cin>>n;
  vector<long long>v(n);
  for(int i=0;i<n;i++)
  cin>>v[i];
  long long x;
  cin>>x;
  pair<long,long>ans;
  ans=indexes(v,x);
  cout<<ans.first<<" "<<ans.second<<endl;

}
