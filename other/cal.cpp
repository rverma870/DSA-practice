#include<iostream>
#include<bits/stdc++.h>
using namespace std;
std::vector<int> v;
int primitivecal(int n,int dp[])
{
  if(n==1){
    return 0;
  }
  else if(n==0){
    return 1;
  }
  else if(n>1){
  std::map<int, int> map;
  int subans;

    if(n%2==0){
      if(dp[n/2]!=-1){
        subans=dp[n/2];
        map.insert(pair<int, int>(subans,n/2));
      }
      else{
        subans=primitivecal(n/2,dp);
        map.insert(pair<int,int>(subans,n/2));
      }
    }
      if(n%3==0){
      if(dp[n/3]!=-1){
        subans=dp[n/3];
        map.insert(pair<int, int>(subans,n/3));
      }
      else{
        subans=primitivecal(n/3,dp);
        map.insert(pair<int,int>(subans,n/3));
      }
    }

      if(dp[n-1]!=-1){
        subans=dp[n-1];
        map.insert(pair<int, int>(subans,n-1));
      }
      else{
        subans=primitivecal(n-1,dp);
        map.insert(pair<int,int>(subans,n-1));
      }


  v.push_back(map.begin()->second);
  dp[map.begin()->second]=map.begin()->first;
  return map.begin()->first+1;
}

}

int main()
{
  int n;
  cin>>n;
  int dp[n+1];
  dp[0]=1;
  dp[1]=0;
  fill(dp+2,dp+n,-1);
  v.push_back(n);

  cout<<primitivecal(n,dp)<<endl;
  for(auto e:v){
      cout<<e<<" ";
    }
  }
