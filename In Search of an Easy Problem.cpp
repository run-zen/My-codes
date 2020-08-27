#include <iostream>

#include <string>

using std::string;

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    string tag = "EASY";
    int tmp;
    for(int i = 0; i<n;i++)
    {
        cin >> tmp;
        if (tmp == 1)
            tag = "HARD";
    }
    cout << tag <<std::endl;
    
    
}