#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  long long a[n];
  int ans=0,j=0;
  for(int i=0;i<n;i++)
    cin>>a[i];
  unordered_map<int, int> index;
	for (int i = 0; i < n; i++)
  {
		j = max(index[a[i]], j);
		ans = max(ans, i - j + 1);
		index[a[i]] = i + 1;
	}
	cout<<ans;
}
