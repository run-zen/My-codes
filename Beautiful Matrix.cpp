#include <iostream>

using namespace std;

int main()
{
    int n;
    int pos_row,pos_col;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> n;
            if (n){
                pos_col = j;pos_row = i;
            }

        }
    }
    pos_row = pos_row - 2;
    pos_col = pos_col -2;
    cout << abs(pos_col)+abs(pos_row)<< std::endl;

}
