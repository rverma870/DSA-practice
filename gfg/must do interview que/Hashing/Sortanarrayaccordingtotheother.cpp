#include<bits/stdc++.h>
using namespace std;

pair<int,int> binarysearch(vector<int> v, int x)
{
  pair<int,int>ans;
  int i=lower_bound(v.begin(),v.end(),x)-v.begin();
  int j=upper_bound(v.begin(),v.end(),x)-v.begin();

  if(v[i]==x && v[j-1]==x)
  {
    return ans=make_pair(i,j-1);
  }
  else
  return ans=make_pair(-1,-1);
}

vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
{
    vector<int>ans;
    sort(A1.begin(),A1.end());
    pair<int,int>p;
    for(int i=0;i<M;i++)
    {
      p=binarysearch(A1,A2[i]);

      if(p.first!=-1 && p.second!=-1)
      {
        ans.insert(ans.begin()+ans.size(), p.second-p.first+1, A2[i]);
        A1.erase(A1.begin()+p.first,A1.begin()+p.second+1);
      }
    }
    if(ans.size()<N)
    {
      for(auto e:A1)
      {
        ans.push_back(e);
      }
    }
    return ans;
}

int main()
{
  int N,M;
  cin>>N>>M;
  vector<int> A1(N),A2(M),ans;
  for(int i=0;i<N;i++)
  cin>>A1[i];
  for(int i=0;i<M;i++)
  cin>>A2[i];
  ans=sortA1ByA2(A1,N,A2,M);
  for(auto e:ans)
  cout<<e<<" ";
}
