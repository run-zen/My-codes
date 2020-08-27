#include <iostream>
#include <vector>

using std::vector;
using namespace std;

struct divi {
   long long x;
   int y;
};

long long NoDivisors(int x, int start, int end, vector<divi> &nums)
{
    long long result = 0;
    int flag = 1,mid;
    for ( int i = 1; i <= x; i++)
    {
        flag = 1;
        if (x % i == 0)
        {
            
            for (int j = start ; j <= end ; j++)
            {
                if (nums[j].x % i == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                result++;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    vector<divi> nums(n);
    for (int i=0; i< n; i++)
    {
        cin >> nums[i].x >> nums[i].y;
    }
    int i = 0;
    while (i < n)
    {
        cout << NoDivisors(nums[i].x, i-nums[i].y, i-1, nums) << endl;
        i++;
    }
    


}
