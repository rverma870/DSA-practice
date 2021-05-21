#include<bits/stdc++.h>
using namespace std;

int main()
{

  long n,x,M=0;
  cin>>n;
  long iarr[n];
  bool b=false;
  for(long i=0;i<n;i++)
  {
     cin>>iarr[i];
     M=max(M,iarr[i]);
  }
  vector<int> a(M+1,0);
  for(int i=0;i<n;i++)
  {
    a[iarr[i]]+=1;
  }
  for(long i=M;i>0;i--)
 {
   int counter=0;
   for(long j=i;j<=M;j+=i)
   {
     if(a[j]>=2)
     {
       cout<<j;
       b=true;
       break;
     }
     if(a[j]>0)
      counter+=1;
      if(counter>1)
      {
        cout<<i<<endl;
        b=true;
        break;
      }
   }
   if(b)
    break;
 }
}
