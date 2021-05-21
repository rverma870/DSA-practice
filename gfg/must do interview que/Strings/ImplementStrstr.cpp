#include<bits/stdc++.h>
using namespace std;

int strstr(string s, string x)
{
	int M = x.length();
	int N = s.length();

	for (int i = 0; i <= N-M; i++)
	{
			int j;

	for (j = 0; j < M; j++)
			if (s[i + j] != x[j])
					break;

	if (j == M)
	{
		return i;
		break;
	}
	}
	return -1;
}

int main()
{
  string s,x;
  cin>>s>>x;
  cout<<strstr(s,x);

}
