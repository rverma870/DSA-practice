#include <bits/stdc++.h>
using namespace std;

vector<int> minPartition(int N)
{
  int notes[]={2000,500,200,100,50,20,10,5,2,1};
  int min_notes_count[11]={0};
  vector<int>ans;
  for(int i=0;i<11;i++)
  {
    min_notes_count[i]=N/notes[i];
    N=N-notes[i]*min_notes_count[i];
    if(N==0)
    break;
  }
  for(int i=0;i<11;i++)
  {
    if(min_notes_count[i]!=0)
    {
      for(int j=0;j<min_notes_count[i];j++)
        ans.push_back(notes[i]);
    }
  }
  return ans;
}

int main()
{
  int N;
  cin>>N;
  vector<int> numbers = minPartition(N);
  for(auto u: numbers)
    cout<<u<<" ";
}
