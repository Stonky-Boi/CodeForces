#include <iostream>
#include <vector>
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
        vector<long long> a(n), b(n);
        for (long long &i : a)
            cin >> i;
        for (long long &i : b)
            cin >> i;
        long long maximum = numeric_limits<long long>::min();
        for (int i = 0; i < n; i++)
            maximum = max(maximum, a[i] - b[i]);
        vector<int> strong;
        for (int i = 0; i < n; i++)
        {
            if (a[i] - b[i] == maximum)
                strong.push_back(i + 1);
        }
        cout << strong.size() << endl;
        for (const int &i : strong)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}