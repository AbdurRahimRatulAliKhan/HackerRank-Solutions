#include <bits/stdc++.h>

using namespace std;

// Complete the almostSorted function below.
int main()
{
    int n;
    int arr[100000];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    int sorted[100000];
    for (int i=0;i<n;i++)
        sorted[i]=arr[i];
    sort(sorted,sorted+n);
    vector<int> diff;
    for (int i=0;i<n;i++)
        if (sorted[i]!=arr[i])
            diff.push_back(i);
    if (diff.size()==0)
        printf("yes\n");  
    else if (diff.size()==2)
        printf("yes\nswap %d %d\n",diff[0]+1,diff[1]+1); 
    else 
    {
        int st = diff[0], ed = diff[diff.size()-1];
        while (st<ed)
        {
            swap(arr[st],arr[ed]);
            st++;
            ed--;
        }
        int flag=1;
        for (int i=0;i<n;i++)
            if (sorted[i]!=arr[i])
            {
                printf("no\n");  
                return 0;
            }
        printf("yes\nreverse %d %d\n",diff[0]+1,diff[diff.size()-1]+1);
    }
    return 0;
}

