#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

struct Segment {
  int start, end;
};

int checkC(vector<int> &c_start, vector<int> &c_end, int start, int end)
{
    int x;
    int n = c_start.size();
    for (int i = 0; i < n; i++)
    {
        if (end <= c_start[i])
            x = 1;
        else if (start >= c_end[i])
            x = 1;
        else
        {
                return 0;
        }
        
    }

    return x;
}

int checkJ(vector<int> &j_start, vector<int> &j_end, int start, int end)
{
    int x = 1;
    int n = j_start.size();
    for (int i = 0; i < n; i++)
    {
        if (end <= j_start[i])
            x = 1;
        else if (start >= j_end[i])
            x = 1;
        else
        {
                return 0;
        }
        
    }

    return x;
}

string getschedule(vector<Segment> &segments, int n)
{
    string result;
    int current = 0;
    string task = "C";
    vector<int> C_start;
    vector<int> C_end;
    vector<int> J_start;
    vector<int> J_end;
    while (current < n)
    {
        if (checkC(C_start,C_end,segments[current].start,segments[current].end))
        {
            task = "C";
            result = result + task;
            C_end.push_back(segments[current].end);
            C_start.push_back(segments[current].start);
            current += 1;
            continue;
        }
        else if(checkJ(J_start,J_end, segments[current].start, segments[current].end))
        {
            task = "J";
            result = result + task;
            J_end.push_back(segments[current].end);
            J_start.push_back(segments[current].start);
            current += 1;
            continue;
        }
        else
        {
            result = "IMPOSSIBLE";
            return result;
        }
    }
    
    return result;
}

int main()
{
    int t,flag = 1;
    std::cin>> t;
    int n;
    string result;
    while (t > 0)
    {
        std::cin >> n;
        std::vector<Segment> segments(n);
        std::vector<int> order;
        for (int i = 0; i < n; ++i) 
        {
            std::cin >> segments[i].start >> segments[i].end;
            order.push_back(i+1);   
        }
        int temp;
        
        for (int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if (segments[i].end > segments[j].end) {
                    temp = segments[i].start;
                    segments[i].start = segments[j].start;
                    segments[j].start = temp;
                    temp = segments[i].end;
                    segments[i].end = segments[j].end;
                    segments[j].end = temp;
                    temp = order[i];
                    order[i]=order[j];
                    order[j]=temp;
                }
            }
        }
        result = getschedule(segments, n);
        if (result[0] != 'I')
        {
            for (int i=0; i<n-1; i++)
            {
                for (int j=i+1;j<n;j++)
                {
                    if (order[i]>order[j])
                    {
                        temp = order[i];
                        order[i] = order[j];
                        order[j] = temp;
                        temp = result[i];
                        result[i] = result[j];
                        result[j] = temp;
                    }
                }
            }
        }
        std::cout <<"Case #"<<flag<<": "<<result<<  std::endl;
        t -= 1;
        flag += 1;
    }
    system("pause");
}