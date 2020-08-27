#include <iostream>
#include <vector>

#define ll long long

using std::vector;
using namespace std;

ll power(int n)
{
    ll b = 1;
    for (int i =0; i < n; i++)
        b = b*10;
    return b;
}
int almostlucky(ll n, vector<ll> luckynums, int dmun)
{
    vector<ll> luck;
    int len = luckynums.size();
    ll a, b = 4 * power(dmun);
    a = b + luckynums[0];

    for (int i =1; i<= len; i++)
    {
       
        luck.push_back(a);
        if (a <= n)
        {
            if (n % a == 0)
            return 1;
        }
        else
            return 0; 
        a = b + luckynums[i];

    }
    b = (b/4)*7;
    a = b + luckynums[0];
    for (int i =1; i<= len; i++)
    {
        
        luck.push_back(a);
        if (a <= n)
        {
            if (n % a == 0)
            return 1;
        }
        else
            return 0; 
        a = b + luckynums[i]; 

    }
    return almostlucky(n,luck,dmun+1);

}
int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<ll> luck;
    luck.push_back(4);
    luck.push_back(7);
    ll n;
    cin >> n;
    if (n % 4 == 0 || n%7 == 0)
        cout << "YES" << endl;
    else
    {
        int i ;
        i = almostlucky(n, luck , 1);
        if (i)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }    
    
}
