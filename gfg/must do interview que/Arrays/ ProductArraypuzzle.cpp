vector<long long int> productExceptSelf(vector<long long int>& nums, int n)
{

    long long int mul=1;
    int countzero=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==0)
        {
            countzero++;
        }
        else
        mul=mul*nums[i];
    }
    if(countzero>1)
    {
         vector<long long int>ans(n,0);
         return ans;
    }
    else
    {
        vector<long long int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0 && countzero==0)
            ans[i]=mul/nums[i];
            else if(nums[i]!=0 && countzero==1)
            ans[i]=0;
            else
            ans[i]=mul;
        }
        return ans;
    }
}
