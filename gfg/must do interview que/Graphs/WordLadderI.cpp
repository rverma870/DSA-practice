#include<bits/stdc++.h>
using namespace std;

int wordLadderLength(string startword, string targetword, vector<string>& wordlist)
{
  unordered_set<string>st;
  int n=wordlist.size();
  for(int i=0;i<n;i++)
    st.insert(wordlist[i]);
  if(st.find(targetword)==st.end())
    return 0;

  int wordlen=startword.length();
  queue<string>q;
  q.push(startword);
  int level=0;
  while(!q.empty())
  {
    level++;
    int qlen=q.size();
    while(qlen--)
    {
      string curr=q.front();
      q.pop();
      for(int i=0;i<wordlen;i++)
      {
        string temp=curr;
        for(char c='a'; c<='z';c++)
        {
          temp[i]=c;
          if(curr==temp)
          continue;
          if(temp==targetword)
          return level+1;
          if(st.find(temp)!=st.end())
          {
            st.erase(temp);
            q.push(temp);
          }
        }
      }
    }
  }
  return 0;
}

int main()
{
  int n;
  cin>>n;
  vector<string>wordlist(n);
  for(int i=0;i<n;i++)
    cin>>wordlist[i];

  string startword,targetword;
  cin>>startword>>targetword;

  cout<<wordLadderLength(startword,targetword,wordlist);
}
