#include<stdio.h>
#include<stdlib.h>

int mutex = 1, empty = 5, full = 0, x = 0;
int front = 0, rear = 0;
#define MAX 5
int buffer[MAX];

void enque(int x) {
    if((rear+1)%MAX == front) {
        return;  // Full check handled by empty semaphore
    }
    rear = (rear+1)%MAX;
    buffer[rear] = x;
}

void deque() {
    if(front == rear) {
        return;  // Empty check handled by full semaphore
    }
    front = (front+1)%MAX;
}

int wait(int s) {
    while(s <= 0);  // Busy wait (basic implementation)
    return --s;
}

int signal(int s) {
    return ++s;
}

void producer() {
    mutex = wait(mutex);
    empty = wait(empty);  // Check buffer space
    
    enque(++x);
    printf("Produced item %d at %d\n", x, rear);
    full = signal(full);  // Increment filled count
    
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);  // Check if items exist
    
    deque();
    printf("Consumed item %d from %d\n", x, front);
    x--;  // Tracking variable
    empty = signal(empty);  // Increment empty space
    
    mutex = signal(mutex);
}

int main() {
    int n;
    printf("\n1.Producer\n2.Consumer\n3.Exit\n");
    
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        
        switch(n) {
            case 1:
                if(mutex == 1 && empty > 0) {
                    producer();
                } else {
                    printf("Buffer full or mutex locked!\n");
                }
                break;
                
            case 2:
                if(mutex == 1 && full > 0) {
                    consumer();
                } else {
                    printf("Buffer empty or mutex locked!\n");
                }
                break;
                
            case 3:
                exit(0);
                
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
