#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (auto &i : a)
            cin >> i;
        b[0] = a[0];
        int max_diff = 0;
        for (int i = 1; i < n; i++)
        {
            b[i] = max(b[i - 1], a[i]);
            max_diff = max(max_diff, b[i] - a[i]);
        }
        int T = (max_diff == 0 ? 0 : ceil(log2(max_diff + 1)));
        cout << T << endl;
    }
    return 0;
}