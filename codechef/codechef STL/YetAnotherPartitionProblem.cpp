#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,q;
  cin>>n>>q;
  int arr[n];
  cin>>arr[0];
  set<int>s;
  s.insert(1);
  for(int i=1;i<n;i++)
  {
      cin>>arr[i];
      if(arr[i]%arr[i-1]!=0)
        s.insert(i+1);
  }

  for(int i=0;i<q;i++)
  {
    int a,b,c;
    cin>>a;
    if(a==1)
    {
      cin>>b>>c;
      s.insert(b);
      if(b<n)
      s.insert(b+1);
      arr[b-1]=c ;
      if(arr[b-1]%arr[b-2]==0 && b!=1)
      {
        auto it = s.find(b);
        s.erase(it);
      }
      if(arr[b]%arr[b-1]==0 && b<n)
      {
        auto it = s.find(b+1);
        s.erase(it);
      }
    }
    else
    {
      cin>>b;
      auto it =s.upper_bound(b);
      if(it!=s.begin())
        it--;
      cout<<*it<<endl;
    }
  }

}
