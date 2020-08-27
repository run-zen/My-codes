#include <iostream>
#include <sstream>

int main()
{
    
    int t,flag = 1;
    std::cin >> t;
    while (t > 0)
    {
        char c[101];
        std::cin >> c;
        int i=0;
        int previous, current = 0, n;
        std::cout <<"Case #"<<flag<<": ";
        while (c[i] != '\0')
        {
            previous = current;
            current = c[i] - '0';
            if (current > previous) {
                n = current - previous;
                while (n > 0) {
                    std::cout << "(";
                    n--;
                }
            }
            else if (current < previous) {
                n = previous - current;
                while (n > 0) {
                    std::cout << ")";
                    n--;
                }
            }
            
            std::cout <<current;
            i++;
        }
        while (current > 0) {
            std::cout <<")";
            current--;
        }
        std::cout << std::endl;
        t -= 1;
        flag += 1;
    }
    system("pause");
}