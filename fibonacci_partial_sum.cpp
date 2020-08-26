#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int get_fibonacci_partial_sum_fast(int m, int n) {

    if(n <=1)
        return n;
    vector<int> series;
    int sum = 0;
    int previous = 0;
    int current  = 1;
    series.push_back(previous);
    series.push_back(current);

    for(int i = 2; i <= n; i++) {
        int tmp = previous;
        previous = current;
        current = (previous + tmp) % 10;
        series.push_back(current);
    }

    for (int i = m; i <= n; i++) {
        
        sum = (sum + series[i]) % 10;
    }

    return sum % 10;
}
int main() {
    long long from, to;
    std::cin >> from >> to;
    from = from % 60;
    to = to % 60;
    if (to < from)
        to +=60;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    system("pause");
}
