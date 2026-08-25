#include <stdio.h>
#include <stdlib.h>

int size=8;

void sort(int arr[])
{
    for(int i=0;i<size-1;i++)
        for(int j=i+1;j<size;j++)
            if(arr[i]>arr[j])
            {
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
}

void CLOOK(int arr[], int head)
{
    int seek_count=0;

    sort(arr);

    printf("\nC-LOOK Disk Scheduling Algorithm\n\n");
    printf("Seek Sequence is\n");

    int i;

    for(i=0;i<size;i++)
        if(arr[i]>=head)
            break;

    for(int j=i;j<size;j++)
    {
        printf("%d\n",arr[j]);
        seek_count+=abs(head-arr[j]);
        head=arr[j];
    }

    if(i>0)
    {
        seek_count+=abs(head-arr[0]);
        head=arr[0];

        printf("%d\n",arr[0]);

        for(int j=1;j<i;j++)
        {
            printf("%d\n",arr[j]);
            seek_count+=abs(head-arr[j]);
            head=arr[j];
        }
    }

    printf("\nTotal number of seek operations: %d\n",seek_count);
}

int main()
{
    int arr[8]={176,79,34,60,92,11,41,114};
    int head=50;

    CLOOK(arr,head);

    return 0;
}
