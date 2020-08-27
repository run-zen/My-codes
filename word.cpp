#include <iostream>
#include <string>

using namespace std;
using std::string;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int upper = 0, lower = 0;
    string word;
    cin >> word;
    int i =0;
    while(word[i] != '\0')
    {
        if (isupper(word[i]))
            upper++;
        else
            lower++;
        i++;
    }

    if (lower >= upper)
    {
        i= 0;
        while (word[i] != '\0') {
            word[i] = tolower(word[i]);
            i++;
        }

    }
    else
    {
        i = 0;
        while (word[i] != '\0') {
            word[i] = toupper(word[i]);
            i++;
        }
    }
    cout<< word<<std::endl;
    

    

}