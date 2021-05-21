vector<int> subarraySum(int arr[], int n, int s)
{
   int i=0,j=0;
   int sum=0;
   vector<int>ans;
   while(i<n || j<n)
   {
       if(sum==s)
       {
           ans.push_back(i+1);
           ans.push_back(j);
           return ans;
           break;
       }

       if(sum<s)
       {
           sum+=arr[j];
           j++;
       }
       else
       {
           sum-=arr[i];
           i++;
       }
   }
   ans.push_back(-1);
   return ans;
}
