int canReach(int A[], int N)
{
    int can_visit=A[0];
    for(int i=0;i<N;i++)
    {
        if(i<=can_visit)
        {
            if(i+A[i]>can_visit)
                can_visit=i+A[i];
        }
        else
        return 0;
    }
    return 1;
}
