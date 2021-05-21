vector<int> leaders(int a[], int n)
{
    vector<int>ans;
    int mx=a[n-1];
    ans.push_back(a[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>=mx)
        {
            mx=a[i];
            ans.push_back(a[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
