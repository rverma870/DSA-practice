long long findNth(long long N)
  {
      long long int ans=0,temp=1;
      while(N)
      {
          ans=ans+temp*(N%9);
          N=N/9;
          temp*=10;
      }
      return ans;
  }
