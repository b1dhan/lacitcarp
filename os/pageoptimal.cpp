#include <stdio.h>

int main()
{
    int incomingStream[] = {4, 1, 2, 4, 5};
    int frames = 3;
    int pageFaults = 0;
    int pages, i, j, k;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    int temp[frames];

    printf("\nOptimal Page Replacement Algorithm\n\n");
    printf("Pg  F1 F2 F3\n");
    printf("----------------\n");

    for(i = 0; i < frames; i++)
        temp[i] = -1;

    for(i = 0; i < pages; i++)
    {
        int found = 0;

        for(j = 0; j < frames; j++)
        {
            if(temp[j] == incomingStream[i])
            {
                found = 1;
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
                int farthest = -1;
                int index = -1;

                for(j = 0; j < frames; j++)
                {
                    int next;

                    for(next = i + 1; next < pages; next++)
                    {
                        if(temp[j] == incomingStream[next])
                            break;
                    }

                    if(next == pages)
                    {
                        index = j;
                        break;
                    }

                    if(next > farthest)
                    {
                        farthest = next;
                        index = j;
                    }
                }

                pos = index;
            }

            temp[pos] = incomingStream[i];
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
