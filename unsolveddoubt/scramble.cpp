#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool> m;
int solve(string A , string B)
{
       if(A.compare(B)==0)
        return true;
    if(A.length()!=B.length() || A.length()<=1)
        return false;

    string key=A;
    key.push_back(' ');
    key.append(B);
    if(m.find(key)!=m.end())
        return m[key];

    bool flag=false;
    int n=A.length();
    for(int i=1;i<n;i++)
    {
        bool cond1=(solve(A.substr(0,i),B.substr(n-i,i))) && (solve(A.substr(i,n-i),B.substr(0,n-i))); //ifswaps
        bool cond2=(solve(A.substr(0,i),B.substr(0,i)))   && (solve(A.substr(i,n-i),B.substr(i,n-i))); //if does't swaps

        if(cond1 or cond2)
            flag=true;
    }

    return m[key]=flag;
}

// int Solution::isScramble(const string A, const string B)
// {
//
//     return solve(A,B,mp);
// }

int main()
{
  string a,b;
  cin>>a>>b;
  cout<<solve(a,b)<<endl;
  // for(auto e:m)
  // cout<<e.first<<" "<<e.second<<endl;

}
