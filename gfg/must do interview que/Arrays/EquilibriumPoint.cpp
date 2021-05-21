int equilibriumPoint(long long a[], int n)
 {
     long long sum=0;
     if(n==1)
     return 1;
     for(int i=0;i<n;i++)
         sum+=a[i];
     long long left=0,right=sum-a[0];
     for(int i=1;i<n;i++)
     {
         left=left+a[i-1];
         right=right-a[i];
         if(left==right)
         {
             return i+1;
             break;
         }
     }
     return -1;
 }
