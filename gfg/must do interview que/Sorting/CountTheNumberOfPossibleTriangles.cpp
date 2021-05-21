#include<bits/stdc++.h>
using namespace std;

int findNumberOfTriangles(int arr[], int n)
{
    sort(arr,arr+n);

    int count = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        int l = 0, r = i - 1;
        while (l < r)
        {
            if (arr[l] + arr[r] > arr[i])
            {

                count += r - l;
                r--;
            }
            else
                l++;
        }
    }
    return count;
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  cout<<findNumberOfTriangles(arr,n);
}
