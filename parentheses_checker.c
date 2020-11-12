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
int pop(struct snode** top_ref) {
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

int match(char c1, char c2) {
     if (c1 == '(' && c2== ')')
          return 1;
     else if (c1 == '{' && c2== '}')
          return 1;
     else if (c1 == '[' && c2== ']')
          return 1;
     else
          return 0;
}
int isbalanced(char exp[]) {
     int i=0;
     struct snode* stack = NULL;

     while(exp[i] != '\0') {

          if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
               push(&stack,exp[i]);

          else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
          {
               if (stack == NULL)
                    return 0;
               else if (!match(pop(&stack), exp[i]))
                    return 0;
          }
          i++;
     }

     if (stack == NULL)
          return 1;
     else
          return 0;
}

int main() {
     char exp[100];
     printf("\nEnter the expressions : ");
     gets(exp);
     if (isbalanced(exp))
          printf("\nBalanced\n");
     else
          printf("\nNot Balanced\n");

     return 0;
}
