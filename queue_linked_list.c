#include<stdio.h>
#include<stdlib.h>

struct qnode {
     int data;
     struct qnode* next;
};

struct Queue {
     struct qnode* front, *rear;

};

struct Queue* createQueue() {
     struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
     temp->front = temp->rear = NULL;

     return temp;
}

struct qnode* newNode(int data) {
     struct qnode* temp = (struct qnode*)malloc(sizeof(struct qnode));

     temp->data = data;
     temp->next = NULL;
     return temp;
}

void Enquene(struct Queue* q, int data) {
     struct qnode* new_node = newNode(data);

     if(q->rear == NULL) {
          q->front = q->rear = new_node;
          return;
     }
     q->rear->next = new_node;
     q->rear = new_node;
}

void Dequeue(struct Queue* q) {
     if(q->front == NULL) {
          printf("\nQueue Underflow : quene is empty");
          return;
     }
     struct qnode* temp = q->front;
     q->front = q->front->next;

     if(q->front == NULL) {
          q->rear = NULL;
     }

     free(temp);
}

void showQueue(struct Queue* q) {
     struct qnode* temp = q->front;
     while(temp != NULL) {
          printf("%d  ", temp->data);
          temp = temp->next;
     }
     printf("\n");
}

int main() {
     struct Queue* q = createQueue();

     int choice;
     while(1) {
          printf("\n1 to enqueue, 2 to Dequeue, 3 to showQueue and Any other to quit.\nEnter choice : ");
          scanf("%d", &choice);
          if(choice == 1) {
               int value = 0;
               while(1) {
                    printf("\nEnter value to push (-1 to exit push) : ");
                    scanf("%d", &value);
                    if(value == -1)
                         break;
                    Enquene(q,value);
               }
          }
          else if(choice == 2)
               Dequeue(q);
          else if (choice == 3)
               showQueue(q);
          else
               break;
     }

     return 0;

}
