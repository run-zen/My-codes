#include <iostream>
#include <time.h>

using namespace std;

void delay(int seconds) {
    int milli_sec = seconds * 1000;

    clock_t start_time = clock();

    while (clock() < start_time + milli_sec)
    ;
}

int main() {
    for (int i = 0; i< 5; i++) {
        cout<<"\a";
        delay(1);
    }

    return 0;
}