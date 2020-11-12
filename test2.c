#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack {
     int data;
     struct Stack* next;
};

int isEmpty(struct Stack* root) {
     return !root;
}

struct Stack* newNode(int data) {
     struct Stack* stack_node = (struct Stack*)malloc(sizeof(struct Stack));
     stack_node->data = data;
     stack_node->next = NULL;
     return stack_node;
}

void push(struct Stack** root, int data) {
     struct Stack* stack_node = newNode(data);

     stack_node->next = *root;
     *root = stack_node;
     printf("\nPushed into the stack: %d\n", data);
}

void pop(struct Stack** root) {
     if(isEmpty(*root))
     {
          printf("\nStack Underflow : The stack is empty.\n");
          return;
     }
     else {
          struct Stack* temp = *root;
          *root = (*root)->next;
          int n = temp->data;
          free(temp);
          printf("\nPopped from stack : %d\n", n);
     }
}

void showStack(struct Stack** root) {

     if(isEmpty(*root)) {
          printf("\nThe stack is empty.\n");
          return;
     }
     else {
          printf("\nThe stack is: \n");
          struct Stack* temp = *root;
          while(temp != NULL) {
               printf("%d  ", temp->data);
               temp = temp->next;
          }
     }
     printf("\n");
}
int peek(struct Stack* root) {
     if(isEmpty(root)) {
          printf("\nStack Underflow : Stack is empty.\n");
          return INT_MIN;
     }
     else {
          return root->data;
     }
}

int main() {
     struct Stack* root = NULL;
     int top;
     push(&root,1);
     push(&root,2);
     push(&root,3);
     push(&root,4);
     push(&root,5);
     top = peek(root);
     if(top != INT_MIN) {
        printf("\nTop Element is : %d\n", top);
     }
     showStack(&root);
     pop(&root);
     showStack(&root);
     top = peek(root);
     if(top != INT_MIN) {
        printf("\nTop Element is : %d\n", top);
     }

}
