#include <iostream>
#include <string>

using namespace std;
using std::string;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    string ans;
    if (n==1)
        cout <<"I hate it"<<std::endl;
    else
    {
        while (i < n)
        {
            if (i%2 == 0)
                ans = ans + "I love";
            else
            {
                    ans = ans + "I hate";
            }
            ans = ans + " that ";
            i++;
        }
        if (n%2 == 0)
            ans = ans + "I love it";
        else
        {
            ans = ans + "I hate it";
        }
        
        cout << ans <<std::endl;
    }

  
}