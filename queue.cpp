// queue implementation using array

#include <iostream>
#include <bits/stdc++.h>

struct Queue
{
    int front, rear, capacity;
    int* queue;

    Queue(int c) {
        front= rear = 0;
        capacity = c;
        queue = new int;
    }

    ~Queue() {delete[] queue;}
    
    void enqueue(int data) {
        if (capacity == rear) {
            printf("\nCannot Insert : Queue is full");
            return;
        }

        else {
            queue[rear] = data;
            rear++;
        }
        return;
    }

    void dequeue() {
        if (front == rear) {
            printf("\nCannot delete : Queue is empty"); 
            return;
        }
        else {
            for (int i=0; i< rear -1;i++) {
                queue[i] = queue[i+1];
            }
            rear--;
        }
        return;
    }

    void display() {
        int i;

        if (front == rear) {
            printf("\nQueue is empty.");
            return;
        }
        
        printf("\nThe queue is:\n");
        for (i = front; i < rear; i++) {
            printf(" %d <--",queue[i]);
        }
        return;
    }
    void disfront() {
        if (front == rear) {
            printf("\nQueue is empty.");
            return;
        }
        printf("\nThe front element of queue : %d", queue[front]);
        return;
    }
};

int main()
{
    Queue q(4);

    q.display();
    
    for(int i=1;i<5;i++) {
        q.enqueue(i);
    }

    q.display();
    q.enqueue(20);
    q.display();
    q.dequeue();
    q.dequeue();
    printf("\nQueue after two deletions :");
    q.display();
    q.disfront();
    return 0;

}
