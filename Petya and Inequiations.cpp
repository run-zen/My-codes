#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,x,y;
    cin >> n >> x >> y;
    if (n > y)
    {
        cout << "-1" << endl;
    }
    else
    {
        long long sum = (y-n+1)*(y-n+1) + (n-1);
        if (sum < x)
        {
            cout << "-1"<< endl;
        }
        else
        {
            cout << (y-n+1) << endl;
            for (int i=1;i < n; i++)
                cout <<"1"<<endl;
        }
        
        
    }

}