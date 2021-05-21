int MissingNumber(vector<int>& array, int n)
{
    int sumarr=0,sum=0;
    for(int i=0;i<n-1;i++)
    {
        sumarr+=array[i];
        sum+=i+1;
    }
    sum+=n;
    return sum-sumarr;
}
