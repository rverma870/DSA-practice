#include<bits/stdc++.h>
using namespace std ;

// int w(int n,int k)
// {
//   if(n==1)
//   return  0;
//   int ans=(w(n-1,k)+k)%n;
//   cout<<ans<<endl;
// }

void josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res = (res + k) % i;
        cout<<res<<" " ;
    }
}
int main()
{
  int n;
  cin>>n;
  josephus(n,2);

}
