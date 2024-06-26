#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {//circular incrementing condition it checks last index pos to front if that is true ie overflow 
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;//here we make front and rear=0 as in circular increment condition never gives -1 so we've to make them as zero
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;//circular incrementing
        }
        queue[rear] = value;//adding value to every index pos
        printf("%d enqueued to the queue\n", value);
    }
}

void dequeue() {
    if (front == -1) {//underflow condition
        printf("Queue is empty\n");
    } else {
        printf("%d dequeued from the queue\n", queue[front]);//as in enqueue front becomes 0 so it deque elemnt at index pos 0 first
        if (front == rear) {
            front = -1;
            rear = -1;//they become -1 when queue is empty after deqing all elements
        } else {
            front = (front + 1) % MAX_SIZE;//it increment after every dequeue is called
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {//while front not equals to zero as they coincid ein circular queue
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;//circularly incrementing
        }
        printf("%d\n", queue[rear]);  // Display the last element separately
    }
}

int main() {
    int choice, value;
    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
