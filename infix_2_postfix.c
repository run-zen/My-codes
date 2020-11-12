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
int Prec(char ch)
{
     switch (ch)
     {
          case '+':
          case '-':
             return 1;
          case '*':
          case '/':
             return 2;
          case '%':
             return 3;
          case '^':
             return 4;
     }
     return -1;
}
int isOperand(char ch)
{
     return (ch >= 'a' && ch <= 'z') ||
          (ch >= 'A' && ch <= 'Z');
}
int isEmpty(struct snode* root) {
     return !root;
}

int infixToPostfix(char exp[]) {
     char postfixExp[100];
     int i=0,k=-1;

     struct snode* root = NULL;

     for(i=0;exp[i] != '\0';i++) {
          if(isOperand(exp[i])) {
               postfixExp[++k] = exp[i];
          }
          else if(exp[i] == '(') {
               push(&root,exp[i]);
          }
          else if(exp[i] == ')') {
               while(!isEmpty(root) && peek(&root) != '(') {
                    postfixExp[++k] = pop(&root);
               }
               if(!isEmpty(root) && peek(&root) != '(')
                    return -1;
               else
                    pop(&root);
          }
          else {
               while (!isEmpty(root) && Prec(exp[i]) <= Prec(peek(&root)))
                    postfixExp[++k] = pop(&root);
               push(&root,exp[i]);
          }
     }
     while (!isEmpty(root))
          postfixExp[++k] = pop(&root);

     postfixExp[++k] = '\0';
     printf("\n%s\n", postfixExp);
}

int main() {
     char exp[100];
     printf("\nEnter the expression : ");
     gets(exp);
     infixToPostfix(exp);

     return 0;
}
