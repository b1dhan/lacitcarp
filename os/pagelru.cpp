#include <stdio.h>

int main()
{
    int incomingStream[] = {4, 1, 2, 4, 5};
    int frames = 3;
    int pageFaults = 0;
    int pages, i, j, k;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    int temp[frames], recent[frames];

    printf("\nLRU Page Replacement Algorithm\n\n");
    printf("Pg  F1 F2 F3\n");
    printf("----------------\n");

    for(i = 0; i < frames; i++)
    {
        temp[i] = -1;
        recent[i] = -1;
    }

    for(i = 0; i < pages; i++)
    {
        int found = 0;

        for(j = 0; j < frames; j++)
        {
            if(temp[j] == incomingStream[i])
            {
                found = 1;
                recent[j] = i;
                break;
            }
        }

        if(!found)
        {
            pageFaults++;

            int pos = -1;

            for(j = 0; j < frames; j++)
            {
                if(temp[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
            {
                pos = 0;
                for(j = 1; j < frames; j++)
                {
                    if(recent[j] < recent[pos])
                        pos = j;
                }
            }

            temp[pos] = incomingStream[i];
            recent[pos] = i;
        }

        printf("%2d ", incomingStream[i]);
        for(k = 0; k < frames; k++)
        {
            if(temp[k] != -1)
                printf("%2d ", temp[k]);
            else
                printf(" - ");
        }
        printf("\n");
    }

    printf("----------------\n");
    printf("Page Faults: %d\n", pageFaults);

    return 0;
}
