#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string b=s;
        reverse(b.begin(),b.end());
        int n=s.length();
        int t[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            t[0][i]=0;
            t[i][0]=0;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s[i-1]==b[j-1])
                    t[i][j]=t[i-1][j-1]+1;
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        cout<<n-t[n][n]<<endl;
    }
}
