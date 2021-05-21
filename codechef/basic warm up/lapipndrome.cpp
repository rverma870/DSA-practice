#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int a1[26],a2[26];
	    for( int i=0 ;i<26 ; i++)
	    {
	        a1[i]=0 ;
	        a2[i]=0 ;
	    }
	    string s;
	    cin>>s;
	    for(int i=0;i<s.length()/2;i++)

	    {
	        //cout<<s[i];
	        a1[int(s[i]-'a')]+=1;
	    }
	    //cout<<"\n" ;
	    for(int i=(s.length()+1)/2;i<(s.length());i++)
	    {
	        //cout<<s[i];
	        a2[int(s[i]-'a')]+=1;
	    }
	    bool check = true ;
	    for(int i=0;i<26;i++)
	    {
	        if(a1[i]!=a2[i])
	        { cout<<"NO\n";
	            check=false ;
	            break;
	        }
        }

        if(check)
            cout<<"YES\n" ;
	}

	return 0;
}
