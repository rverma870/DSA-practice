int maxProduct(vector<int>& nums)
 {
     int ans=INT_MIN,mul;
     for(int i=0;i<nums.size();i++)
     {
          mul=nums[i];
         for(int j=i+1;j<nums.size();j++)
         {
             mul=mul*nums[j];
             ans=max(ans,mul);
         }
         ans=max(ans,nums[i]);
     }
     return ans;
 }
