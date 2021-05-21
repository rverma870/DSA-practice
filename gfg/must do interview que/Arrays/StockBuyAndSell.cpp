#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > stockBuySell(vector<int> A, int n)
{
    int buy=0,sell=0,profit=0;
    vector<vector<int>>ans;
    vector<int>temp(2);
    for(int i=1;i<n;i++)
    {
        if(A[i]>A[buy])
        {
            if(A[i]-A[buy]>profit)
            {
                profit=A[i]-A[buy];
                sell=i;
            }
            else
            {
                temp[0]=buy;
                temp[1]=sell;
                if(buy!=sell)
                ans.push_back(temp);
                buy=i;
                sell=i;
                profit=0;
            }

        }
        else
        {
            temp[0]=buy;
            temp[1]=sell;
            if(buy!=sell)
            ans.push_back(temp);
            buy=i;
            sell=i;
            profit=0;
        }
    }
    temp[0]=buy;
    temp[1]=sell;
    if(buy!=sell)
    ans.push_back(temp);
    return ans;
}

int main()
{
  int n;
  cin>>n;
  vector<int>A(n);
  for(int i=0;i<n;i++)
    cin>>A[i];
  vector<vector<int>>ans;
  ans=stockBuySell(A,n);
  for(int i=0;i<ans.size();i++)
    cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
}
