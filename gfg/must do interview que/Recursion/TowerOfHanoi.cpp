#include<bits/stdc++.h>
using namespace std;

long long toh(int N, int from, int to, int aux)
{
  if(N==1)
  {
    cout<<"move disk 1 from rod "<<from<<" to rod "<<to<<"\n";
    return 1;
  }
   int a1=toh(N-1,from,aux,to);
   cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<"\n";
   int a2=toh(N-1,aux,to,from);
   return a1+1+a2;
}
int main()
{
  int n;
  cin>>n;
  cout<<toh(n,1,3,2);
}
