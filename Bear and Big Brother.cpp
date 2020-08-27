#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a,b;
    cin >> a >> b;
    int years = 0;
    while (a <= b)
    {
        a = a*3;
        b = b*2;
        years++;
    }
    cout << years <<std::endl;
    
}