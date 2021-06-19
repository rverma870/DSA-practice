#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* X, char* Y, int m, int n)
{
    int t[m+1][n+1];
    for(int i=0;i<=m;i++)
        t[i][0]=0;
    for(int j=0;j<=n;j++)
        t[0][j]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return m+n-t[m][n];
}

int main()
{
  char X[10001], Y[10001];
	cin >> X >> Y;
	cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;

}
