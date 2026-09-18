#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int r[n];
        for (auto &i : r)
            cin >> i;
        int m;
        cin >> m;
        int b[m];
        for (auto &i : b)
            cin >> i;
        int max_r = 0, sum_r = 0;
        for (auto x : r)
        {
            sum_r += x;
            if (sum_r > max_r)
                max_r = sum_r;
        }
        int max_b = 0, sum_b = 0;
        for (auto x : b)
        {
            sum_b += x;
            if (sum_b > max_b)
                max_b = sum_b;
        }
        cout << max_r + max_b << endl;
    }
    return 0;
}