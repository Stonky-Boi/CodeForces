#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int left = (n - 1) / 2;
        int right = n / 2;
        long long ways_x = x[right] - x[left] + 1;
        long long ways_y = y[right] - y[left] + 1;
        cout << ways_x * ways_y << endl;
    }
    return 0;
}