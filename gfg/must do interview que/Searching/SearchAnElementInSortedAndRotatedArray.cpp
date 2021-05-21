#include<bits/stdc++.h>
using namespace std;

int binarysearch( vector<int>vec,int l,int r, int k)
{
    int mid,ans;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(vec[mid]<k)
           l=mid+1;
        else if(vec[mid]>k)
           r=mid-1;
        else
           return ans=mid;
    }
    return -1;
}

int Search(vector<int> vec, int K)
{
        int n=vec.size();
        int l=0,h=n-1,mid,ans=0;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(vec[mid]>vec[mid-1] && vec[mid]<vec[mid+1] && vec[mid]<vec[0])
            {
              h=mid-1;
            }
            else if(vec[mid]>vec[mid-1] && vec[mid]<vec[mid+1])
            {
              l=mid+1;
              ans=mid;
            }
            else if(vec[mid]>vec[mid-1] && vec[mid]>vec[mid+1])
            {
              ans=mid;
              break;
            }
            else if(vec[mid]<vec[mid-1])
            {
              ans=mid-1;
              break;
            }

        }
        if(K>=vec[0] && K<=vec[ans])
        return binarysearch(vec,0,ans,K);
        return binarysearch(vec,mid+1,n-1,K);
}
int main()
{
  int n;
  cin>>n;
  vector<int>vec(n);
  for(int i=0;i<n;i++)
    cin>>vec[i];
  int k;
  cin>>k;
  cout<<Search(vec,k);
}
