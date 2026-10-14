#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int seconds = 0, b = numeric_limits<int>::min();
        for (int &i : a)
        {
            cin >> i;
            b = max(b, i);
            seconds = max(seconds, b - i);
        }
        cout << ceil(log2(seconds + 1)) << endl;
    }
    return 0;
}