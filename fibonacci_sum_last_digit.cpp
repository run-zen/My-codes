#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;
    int sum = 1;
    int previous = 0;
    int current  = 1;

    for ( long long i = 2; i<= n; i++) {
        int tmp = previous;
        previous = current;
        current = (previous + tmp) % 10;
        sum = (sum + current) % 10;
    }

    return sum % 10;

}

int main() {
    long long n = 0;
    std::cin >> n;
    n = n % 60;
    std::cout << fibonacci_sum_fast(n) << std::endl;
    system("pause");
}
