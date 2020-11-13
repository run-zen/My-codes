#include<stdio.h>
#include<stdlib.h>

struct snode {
     char data;
     struct snode* next;
};

void push(struct snode** top_ref, char data) {

     struct snode* new_node = (struct snode*)malloc(sizeof(struct snode));

     new_node->data = data;
     new_node->next = *top_ref;
     *top_ref = new_node;
}
char pop(struct snode** top_ref) {
     if(*top_ref == NULL) {
          printf("\nstack overflow\n");
          getchar();
          exit(1);
     }
     else {
          struct snode* temp = *top_ref;
          char popped = temp->data;
          *top_ref = temp->next;
          free(temp);
          return popped;
     }

}
char peek(struct snode** top_ref) {
     if(*top_ref == NULL) {
          printf("\nstack overflow\n");
          getchar();
          exit(1);
     }
     else {
          return (*top_ref)->data;
     }
}

int isEmpty(struct snode* root) {
     return !root;
}

void reverseList(char exp[]) {
     char ch;
     struct snode* root=NULL;
     for(int i=0;exp[i] != '\0'; i++) {
          push(&root,exp[i]);
     }
     int i=-1;
     while(!isEmpty(root)) {
          ch = pop(&root);
          exp[++i] = ch;
     }
     exp[++i] = '\0';
}

int main() {
     static char exp[100];
     printf("\nEnter the string to reverse : ");
     gets(exp);
     reverseList(exp);
     for(int i=0;exp[i] != '\0'; i++) {
          printf("%c", exp[i]);
     }

     return 0;
}
