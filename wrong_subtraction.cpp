#include <iostream>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long n;
    int k;
    int last;
    std::cin >> n >> k;
    while (k > 0)
    {
        last = n % 10;
        if (last == 0)
            n = n/10;
        else
        {
            n = n-1;
        }

        k = k-1;
    }

    std::cout << n <<std::endl;
   
}