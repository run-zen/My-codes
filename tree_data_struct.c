#include <stdio.h>
#include <stdlib.h>

struct node {
     int data;
     struct node* left;
     struct node* right;
};

struct node* newNode(int data) {
      struct node* new_node = (struct node*)malloc(sizeof(struct node));

      new_node->data = data;

      new_node->left = NULL;
      new_node->right = NULL;

      return(new_node);
}

void printTree(struct node* root) {
     while(root != NULL) {
          printf("%d\n", root->data);
          printf("/ \\\n");
          printTree(root->left);
          printTree(root->right);
          break;
     }
}

int main() {
     struct node* head = NULL;
     head = newNode(1);

     head->left = newNode(2);
     head->right = newNode(3);

     printTree(head);

     return 0;
}
