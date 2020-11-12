#include <bits/stdc++.h>

using namespace std;

bool isOperand(char ch) {
     return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

string postfixToInfix(string exp) {
     stack<string> root;

     for(int i=0;exp[i] != '\0' ; i++) {
          if(isOperand(exp[i])) {
               string ch(1,exp[i]);
               root.push(ch);
          }
          else {
               string op1 = root.top();
               root.pop();
               string op2 = root.top();
               root.pop();
               root.push("("+op2+exp[i]+op1+")");
          }
     }
     return root.top();
}

int main() {
     string exp;
     cout<<"\nEnter the postfix expression : ";
     cin>>exp;
     cout<<"\n"<<postfixToInfix(exp)<< endl;

     return 0;
}
