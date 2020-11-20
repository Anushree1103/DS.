#include <stdio.h>

int a[50];
int binsearch(int low, int high, int key)
{
    int mid;
    while(low<=high)
    {
        mid =(low+high)/2;
        
        if(a[mid]<key)
        {
            low= mid+1;
        }
        else if(a[mid]>key)
        {
            high= mid-1;
        }
        else
            return mid;
    }
    return -1;
}

int main()
{
    int i, val, n, pos;
    
    printf("Enter the size of array ");
    scanf("%d", &n);
    printf("Enter the sorted values of the array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the value to search ");
    scanf("%d", &val);
    pos= binsearch(0, n-1, val);
    if(pos==-1)
    {
        printf("Values not present!");
    }
    else
    {
        printf("Values present at position %d", pos);
    }
}


