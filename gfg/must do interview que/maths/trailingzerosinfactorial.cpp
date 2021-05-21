int trailingZeroes(int N)
   {
       int i=5,count=0;
       while (N/i>=1)
       {
           count+=N/i;
           i*=5;
       }
       return count;
   }
