#include<stdio.h>
#include<stdlib.h>

struct snode {
     int data;
     struct snode* next;
};

struct snode* A = NULL;
struct snode* B = NULL;
struct snode* C = NULL;

void push(struct snode** top_ref, char data) {
     struct snode* new_node = (struct snode*)malloc(sizeof(struct snode));

     new_node->data = data;
     new_node->next = *top_ref;
     *top_ref = new_node;
}

int pop(struct snode** top_ref) {
     if(*top_ref == NULL) {
          printf("\nstack overflow pop\n");
          getchar();
          exit(1);
     }
     else {
          struct snode* temp = *top_ref;
          int popped = temp->data;
          *top_ref = temp->next;
          free(temp);
          return popped;
     }

}

int peek(struct snode** top_ref) {
     if(*top_ref == NULL) {
          printf("\nstack overflow\n");
          getchar();
          exit(1);
     }
     else {
          return (*top_ref)->data;
     }
}

int popFromRod(char from_rod) {
     int popped;
     if(from_rod == 'A')
          popped = pop(&A);
     else if(from_rod == 'B')
          popped = pop(&B);
     else
          popped = pop(&C);

     return popped;
}

void pushToRod(char to_rod, int disk) {
     if(to_rod == 'A') {
          push(&A,disk);
     }
     else if (to_rod == 'B') {
          push(&B,disk);
     }
     else
          push(&C,disk);
}

void towerOfHonai(int n, char from_rod, char to_rod, char aux_rod) {
     int disk;
     if (n == 1) {
          disk = popFromRod(from_rod);
          pushToRod(to_rod, disk);
          printf("\nMoved Disk 1 from rod %c to rod %c.", from_rod, to_rod);
          return;
     }
     towerOfHonai(n-1,from_rod,aux_rod,to_rod);
     printf("\nMoved Disk %d from rod %c to rod %c", n,from_rod, to_rod);
     towerOfHonai(n-1,aux_rod,to_rod, from_rod);
}

int main() {
     int n;
     printf("\nEnter the number of disks : ");
     scanf("%d", &n);
     for (int i=n;i >= 1; i--) {
          push(&A,i);
     }
     towerOfHonai(n,'A','C','B');

     printf("\n");
     return 0;
}
