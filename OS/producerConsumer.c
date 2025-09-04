/*           PRODUCER CONSUMER USING SEMAPHORES

Name : Denkada Nithin
Roll : 325103311L01
*/

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

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0)) { 
                    producer();
                } else {
                    printf("Buffer is full!!");
                }
                break;

            case 2:
                if ((mutex == 1) && (full != 0)) { 
                    consumer();
                } else {
                    printf("Buffer is empty!!");
                }
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.");
        }
    }
    return 0;
}


int waitS(int s) {
    return (--s);
}
int signalS(int s) {
    return (++s);
}

void producer() {
    mutex = waitS(mutex);
    full  = signalS(full);
    empty = waitS(empty);
    x++;
    printf("\nProducer produces item %d", x);
    mutex = signalS(mutex);
}

void consumer() {
    mutex = waitS(mutex);
    full  = waitS(full);
    empty = signalS(empty);
    printf("\nConsumer consumes item %d", x);
    x--;
    mutex = signalS(mutex);
}