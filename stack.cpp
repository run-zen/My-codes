#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void showstack(stack <int> s) {
    if (s.empty())
        cout <<"Empty stack";

    while(!s.empty()) {
        cout << s.top() << "\t";
        s.pop();
    }
    
}

int main() {
    stack <int> studentIds;

    cout << "\nThe stack before initializing : ";
    showstack(studentIds);

    for (int i = 1 ; i<= 10 ;i++) {
        studentIds.push(1914000 + i);
    }

    cout <<"\nThe stack after initializing : ";
    showstack(studentIds);

    return 0;


}