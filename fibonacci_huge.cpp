#include <iostream>

/*long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}*/

long long pisano_period(long long m)   {

    long long previous = 0;
    long long current  = 1;
    long long period = 2;
    while(true) {
        long long tmp = previous;
        previous = current;
        current = previous + tmp;
        current = current % m;
        if (current % m == 0) {
            if ((current + previous) % m == 1)
                return period;
        }
        period++;
    }
}

long long fibonacci_mod(long long n, long long m) {
    long long previous = 0;
    long long current  = 1;
    if (n <=1)
        return n;

    for(long long i = 2; i <= n; i++) {
        long long tmp = previous;
        previous = current;
        current = previous + tmp;
        current = current % m;
    }
    return current;
}

int main() {

    long long n, m;
    std::cin >> n >> m;
    long long period = pisano_period(m);
    n = n % period;
    std::cout << fibonacci_mod(n,m) << '\n';
    system("pause");
}
