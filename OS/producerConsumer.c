#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full  = 0;
int empty = 3;
int x     = 0;

int waitS(int);
int signalS(int);
void producer();
void consumer();

int main() {
    int n;
    printf("\n1. Producer\n2. Consumer\n3. Exit");

    // Main loop to repeatedly display the menu and wait for user choice
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0)) { 
                    // Check if mutex is available and there is space in the buffer
                    producer();
                } else {
                    printf("Buffer is full!!");
                }
                break;

            case 2:
                if ((mutex == 1) && (full != 0)) { 
                    // Check if mutex is available and there are items to consume
                    consumer();
                } else {
                    printf("Buffer is empty!!");
                }
                break;

            case 3:
                exit(0); // Exit the program
                break;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.");
        }
    }
    return 0;
}

// Wait function (decrements a value and returns it)
int waitS(int s) {
    return (--s);
}

// Signal function (increments a value and returns it)
int signalS(int s) {
    return (++s);
}

// Producer function
void producer() {
    mutex = waitS(mutex);   // Acquire mutex lock
    full  = signalS(full);  // Increment the full counter (producing an item)
    empty = waitS(empty);   // Decrement the empty counter (space is reduced)
    x++;                    // Increment the item counter

    printf("\nProducer produces item %d", x);

    mutex = signalS(mutex); // Release mutex lock
}

// Consumer function
void consumer() {
    mutex = waitS(mutex);   // Acquire mutex lock
    full  = waitS(full);    // Decrement the full counter (consuming an item)
    empty = signalS(empty); // Increment the empty counter (space is increased)

    printf("\nConsumer consumes item %d", x);
    x--;                    // Decrement the item counter

    mutex = signalS(mutex); // Release mutex lock
}
