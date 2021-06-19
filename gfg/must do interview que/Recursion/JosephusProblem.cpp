#include<bits/stdc++.h>
using namespace std;

void solve(int idx,int n,vector<int>&cur_people,int k)
{
  if(cur_people.size()==1)
  {
    return ;
  }
  idx= (idx+k)%cur_people.size();
  cur_people.erase(cur_people.begin()+idx);
  solve(idx,n,cur_people,k);
}
int josephus(int n, int k)
{
   k--;
   vector<int>cur_people(n);
   for(int i=1;i<=n;i++)
     cur_people[i-1]=i;
   solve(0,n,cur_people,k);
   return cur_people[0];
}
int main()
{
  int n,k;
  cin>>n>>k;
  cout<<josephus(n,k);
}
