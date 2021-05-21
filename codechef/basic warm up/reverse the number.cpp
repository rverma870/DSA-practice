#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;

	while(t--)
	{
	    int m;
	    int rd = 0 ;
	    cin>>m;
	    while(m)
	    {
	       rd = rd*10 + m%10 ;
	       m=m/10;

	    }
	    cout<<rd<<"\n" ;
	}
	return 0;
}
