#include<bits/stdc++.h>
using namespace std ;
int main()
{
	int n , m ;
	cin>>n>>m ;
	long a[n] ;
	int pos[n+1] ;
	int ans=0 ;
	pos[0] = -1 ;
	set<long> s ;
	for(int i=0 ; i<n ; i++ )
	{
		cin>>a[i] ;
		if(s.find(a[i]-1)!=s.end())
			s.erase(a[i]-1) ;
		s.insert(a[i]) ;
		pos[a[i]]=i+1 ;
	}
	ans=s.size() ;
	int p,q ;
	while (m--)
	{
		cin>>p>>q ;
		long v1 = a[p-1] , v2=a[q-1] ;

      //checking for v1
  	//Smaller of v1
  	if(v1!=1)
    {
    	if(p>pos[v1-1] and q<=pos[v1-1])// going left
    		ans++;
    	if(p<pos[v1-1] and q>=pos[v1-1]) // going right
    		ans--;
    }
  	//Greater of v1
  	if(v1!=n)
    {
      if(p>pos[v1+1] and q<=pos[v1+1]) // going left
    		ans--;
    	if(p<pos[v1+1] and q>=pos[v1+1]) // going right
    		ans++;
    }
  // checking for v2
  //	Smaller of v2
  	if(v2-v1!=1 and v2!=1)
  	{
      if(q>pos[v2-1] and p<= pos[v2-1]) // going left
  		ans++ ;
  	  if(q<pos[v2-1] and p>=pos[v2-1]) // going right
  		ans-- ;
    }
  //	Greater of v2
  	if(v1-v2!=1 and v2!=n)
  	{
      if(q>pos[v2+1] and p<=pos[v2+1]) // going left
  		ans--;
  	  if(q<pos[v2+1] and p>=pos[v2+1]) // going right
  		ans++;
    }
  	swap(a[p-1],a[q-1]);
  	pos[v1]=q;
  	pos[v2]=p;

    cout<<ans<<endl;

	}

}
