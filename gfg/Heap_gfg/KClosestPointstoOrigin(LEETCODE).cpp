#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
  priority_queue<pair<int,pair<int,int>>>q;
  vector<vector<int>>ans;
  for(int i=0;i<points.size();i++)
  {
    q.push(make_pair(points[i][0]*points[i][0] + points[i][1]*points[i][1] , make_pair(points[i][0] , points[i][1] ) ) );
    if(q.size()>k)
        q.pop();
  }

  while(!q.empty())
  {
    vector<int>temp;
    temp.push_back(q.top().second.first);
    temp.push_back(q.top().second.second);
    ans.push_back(temp);
    q.pop();
  }
  return ans;
}

int main()
{
  int n,k;
  cin>>n>>k;
  vector<vector<int>>points(n);
  for(int i=0;i<n;i++)
  {
    vector<int>temp(2);
    for(int j=0;j<2;j++)
    {
      cin>>temp[j];
    }
    points[i]=temp;
  }
  vector<vector<int>>ans=kClosest(points,k);
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i][0]<<" "<<ans[i][1];
  }
}
