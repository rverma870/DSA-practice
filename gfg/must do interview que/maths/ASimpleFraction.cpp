string fractionToDecimal(int numerator, int denominator)
	{
	    string res;
        map<int,int> mp;
        int rem=numerator%denominator;
        while(rem!=0 && mp.find(rem)==mp.end())
        {
          mp[rem]=res.length();
          rem=rem*10;
          int res_part=rem/denominator;
          res+=to_string(res_part);
          rem=rem%denominator;
        }

        if(rem==0 && res!="")
          cout<<numerator/denominator<<"."<<res;
        else if(rem==0 && res=="")
          cout<<numerator/denominator;
        else if(mp[rem]!=0)
          cout<<numerator/denominator<<"."<<res.substr(0,mp[rem])<<"("<<res.substr(mp[rem])<<")";
        else
          cout<<numerator/denominator<<"."<<"("<<res.substr(mp[rem])<<")";
    }
