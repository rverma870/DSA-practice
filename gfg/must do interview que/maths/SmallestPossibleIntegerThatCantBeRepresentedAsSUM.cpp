long long smallestpositive(vector<long long> array, int n)
    {
        sort(array.begin(),array.end());
        long  ans=1;
        for(int i=0;i<n && array[i]<=ans;i++)
            ans=ans+array[i];
        return ans;
    } 
