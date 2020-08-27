#include <iostream>
#include <string>

using std::string;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string first_string,second_string;
    cin >> first_string >> second_string;
    int result = 0;
    int i = 0;
    char a,b;
    while (first_string[i] != '\0')
    {
        a = first_string[i];
        b = second_string[i];
        a = tolower(a);
        b = tolower(b);
        if (a > b)
        {
            result = 1;
            break;
        }
        else if (a < b)
        {
            result = -1;
            break;
        }
        i++;
    }
    cout << result << endl;
     
}