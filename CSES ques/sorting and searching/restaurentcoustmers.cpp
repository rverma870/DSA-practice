#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,x,y,t,temp=0,count=0;
  vector<int>v1,v2;
  cin>>n;
  t=n;
  while(t--)
  {
    cin>>x>>y;
    v1.push_back(x);
    v2.push_back(y);
  }
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  int j=0;  
  for(int i=0;i<n;i++)
  {
    if(v1[i]<v2[j])
    {
      temp++;
      count=max(count,temp);
    }
    else
    {
      temp--;
      j++;
      i--;
    }

  }
  cout<<count<<"\n";
}
