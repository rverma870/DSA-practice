#include<bits/stdc++.h>
using namespace std;

vector<int> increment(vector<int> arr ,int N)
{
        for(int i=N-1;i>=0;i--)
        {
            if(arr[i]<9)
            {
                arr[i]+=1;
                return arr;
                break;
            }
            else
            {
              arr[i]=0;
              if(i==0)
              {
                arr.insert(arr.begin(), 1);
                return arr;
              }
            }
        }
}

int main()
{
  vector<int>arr;
  arr.push_back(9);
  arr.push_back(9);
  arr.push_back(9);
  vector<int>ans;
   ans=increment(arr,3);
  for(auto e:ans)
  cout<<e<<" ";

}
