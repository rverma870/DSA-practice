#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define SIZE 10000
void factorial(vector<long long int>& fact)
{
    int i;
    fact[0] = 1;
    for (i = 1; i <= SIZE; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}
int main()
{
    vector<long long int> fact(SIZE + 1, 0);
    int arr[5] = {3, 10, 200, 20, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    factorial(fact);
    for(int i=0;i<n;i++)
      cout<<fact[arr[i]]<<" ";
}
