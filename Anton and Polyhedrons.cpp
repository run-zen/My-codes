#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    int tmp;
    string shapes;
    vector<int> a;
    long long sum = 0;
    for(int i = 0;i<n;i++)
    {
        cin >> shapes;
        tmp = shapes[0];
        switch (tmp)
        {
            case 84: sum = sum + 4;
                     break;
            case 67: sum  = sum + 6;
                     break;
            case 79: sum = sum + 8;
                     break;
            case 68: sum = sum + 12;
                     break;
            case 73: sum = sum + 20;
                     break;  
        }
    }
    cout << sum << std::endl;
   

}