#include <iostream>

int main()
{
    int t,flag = 1;
    std::cin >> t;
    int n;
    int k,r,c;
    int sum_r = 0, sum_c = 0;
    while (t > 0)  {
        std::cin >> n;
        k = 0;
        r = 0;
        c = 0;
        int a[n][n];
        int zeros_r[n][n], zeros_c[n][n];
        for (int i= 0;i<n;i++) 
            for (int j=0;j<n;j++) {
                zeros_r[i][j] = 0;
                zeros_c[i][j] = 0;
            }
        for (int i=0; i< n; i++) {
            for (int j=0; j<n; j++) {
                std::cin >> a[i][j];
                zeros_r[i][a[i][j]-1] = 1;
                zeros_c[j][a[i][j]-1] = 1;
            }
            k = k + a[i][i];
        }
        for (int i=0;i<n;i++) {
            sum_c = 0;
            sum_r = 0;
            for (int j=0;j<n;j++) {
                sum_r = sum_r + zeros_r[i][j];
                sum_c = sum_c + zeros_c[i][j];
            }
            if (sum_c < n)
                c += 1;
            if (sum_r < n)
                r += 1;
        }
        std::cout <<"Case #"<<flag<<": "<< k <<" "<< r <<" "<< c << std::endl;
        t = t-1;
        flag +=1;

    }
    system("pause");
}
