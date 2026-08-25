#include <stdio.h>
int main()
{
    int incomingStream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;
    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
     printf("\nFIFO Page Replacement Algorithm\n\n");
    printf("Pg  F1 F2 F3\n");
    printf("----------------\n");
    int temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }
    for (m = 0; m < pages; m++)
    {
        s = 0;
        for (n = 0; n < frames; n++)
        {
            if (incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if ((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if (s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
        printf("%2d ", incomingStream[m]);
        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                printf("%2d ", temp[n]);
            else
                printf(" - ");
        }
        printf("\n");
    }
    printf("----------------\n");
    printf("Page Faults: %d\n", pageFaults);
    return 0;
}
