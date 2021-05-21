#include<bits/stdc++.h>
using namespace std;

int main()
{
  long n,m,x;
  cin>>n>>m;
  vector<long>VN,VM;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    VN.push_back(x);
  }
  for(int i=0;i<m;i++)
  {
    cin>>x;
    VM.push_back(x);
  }
  auto it = min_element(VM.begin(),VM.end());
  int minofVM=it-VM.begin();
  for(int i=0;i<n;i++)
  {
    cout<<i<<" "<<minofVM<<endl;
  }

  it=max_element(VN.begin(),VN.end());
  for(int i=0;i<m;i++)
  {
    if(i!=minofVM)
    cout<<it-VN.begin()<<" "<<i<<endl;
  }

}
