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

char * reverseList(char exp[],char* p) {
     char ch;
     struct snode* root=NULL;
     for(int i=0;exp[i] != '\0'; i++) {
          push(&root,exp[i]);
     }
     int i=0;
     while(!isEmpty(root)) {
          ch = pop(&root);
          p[i] = ch;
          i++;
     }
     p[i] = '\0';
     return p;
}

int main() {
     char exp[100];
     printf("\nEnter the string to reverse : ");
     gets(exp);
     int len = 0;
     for(int i=0;exp[i] != '\0';i++) {
          len++;
     }
     char ch[100];
     char* p;
     p = reverseList(exp,ch);
     for(int i=0;i<len;i++) {
          printf("%c", *(p+i));
     }

     return 0;
}
