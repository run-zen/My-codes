#include <iostream>
#include <vector>

using std::vector;
using namespace std;

struct restrict {
    int start,end,max;
};

int main()
{
    int n,h,m;
    cin >> n >> h >> m;
    vector<restrict> res(m);
    vector<int> house(n);
    for (int i=0;i<n;i++)
        house[i] = h*h;
    for (int i = 0; i< m; i++)
    {
        cin >> res[i].start >> res[i].end >> res[i].max;
    }
    int tmp;
    for (int i=0;i<m-1;i++)
    {
        for (int j=i;j<m;j++)
        {
            if (res[i].max < res[j].max)
            {
                tmp = res[i].max;
                res[i].max = res[j].max;
                res[j].max = tmp;
                tmp = res[i].start;
                res[i].start = res[j].start;
                res[j].start = tmp;
                tmp = res[i].end;
                res[i].end = res[j].end;
                res[j].end = tmp;
            }
        }
    }
    int j = 0;
    while(j < m)
    {
        for (int i = res[j].start-1;i<= res[j].end-1;i++)
        {
            house[i]= res[j].max * res[j].max;
        }
        j++;
    }
    long long profit = 0;
    for (j=0;j< n;j++) {
        profit = profit + house[j];
    }
    cout <<"\n"<< profit<< endl;
    
}