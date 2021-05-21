int findZeroes(int arr[], int n, int m)
{
    int countzero=0;
    int i=0,j=0,subarray=0;
    while(i<n && j<n)
    {

        if(countzero<=m)
        {
            subarray=max(subarray,j-i);
            if(arr[j]==0)
            countzero++;
            j++;
        }
        else
        {
            if(arr[i]==0)
            countzero--;
            i++;
        }
    }
    if(countzero>m)
    {
        while(i<n && countzero>m)
        {
            if(arr[i]==0)
            countzero--;
            i++;
        }
        return max(subarray,j-i);
    }
    else
    return max(subarray,j-i);
}  
