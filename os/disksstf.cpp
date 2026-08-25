#include <stdio.h>
#include <math.h>

int size = 8;

void SSTF(int arr[], int head)
{
    int visited[8] = {0};
    int seek_count = 0;

    printf("\nSSTF Disk Scheduling Algorithm\n\n");
    printf("Seek Sequence is\n");

    for(int i = 0; i < size; i++)
    {
        int min = 100000, index = -1;

        for(int j = 0; j < size; j++)
        {
            if(!visited[j] && abs(head - arr[j]) < min)
            {
                min = abs(head - arr[j]);
                index = j;
            }
        }

        visited[index] = 1;
        seek_count += abs(head - arr[index]);
        head = arr[index];

        printf("%d\n", head);
    }

    printf("\nTotal number of seek operations: %d\n", seek_count);
}

int main()
{
    int arr[8] = {176,79,34,60,92,11,41,114};
    int head = 50;

    SSTF(arr, head);

    return 0;
}
