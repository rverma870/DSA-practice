#include<bits/stdc++.h>
using namespace std;

int isValid(vector<vector<int>> mat)
{
  set<string>st;
  string row="",col="",box="";
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(mat[i][j]!=0)
      {
        row="Row" + to_string(i)+ "*" + to_string(mat[i][j]);
        col="Col" + to_string(j)+ "*" + to_string(mat[i][j]);
        int x= (i/3)*3+j/3;
        box="Box" + to_string(x)+ "*" + to_string(mat[i][j]);
        if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end())
        {cout<<i<<" "<<j<<endl;
            return 0;}
        else
        {
          st.insert(row);
          st.insert(col);
          st.insert(box);
        }
      }
    }
  }
  return 1;
}

int main()
{
  vector<vector<int>>mat(9);
  for(int i=0;i<9;i++)
  {
    vector<int>temp(9);
    for(int j=0;j<9;j++)
    {
      cin>>temp[j];
    }
    mat[i]=temp;
  }
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    cout<<mat[i][j]<<" ";
    cout<<endl;
  }
  cout<<isValid(mat);
}
