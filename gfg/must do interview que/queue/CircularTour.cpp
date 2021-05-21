#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump p[],int n)
{
  int dist=0,petrol=0,start=0,tank=0;
  for(int i=0;i<n;i++)
  {
      dist+=p[i].distance;
      petrol+=p[i].petrol;
      tank+=p[i].petrol - p[i].distance;
      if(tank<0)
      {
          tank=0;
          start=i+1;
      }
  }
  if(petrol<dist)
    return -1;
  return start;
}

int main()
{
  int n;
  cin>>n;
  petrolPump arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i].petrol;
  for(int i=0;i<n;i++)
    cin>>arr[i].distance;
  cout<<tour(arr,n);    
}
