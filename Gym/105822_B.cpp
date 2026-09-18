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
        vector<long long> a(n);
        for (auto &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        vector<long long> gap(n - 1);
        for (int i = 0; i < n - 1; i++)
            gap[i] = a[i + 1] - a[i];
        long long operations = LLONG_MAX;
        long long best = gap[0];
        for (int i = 2; i < n - 1; i++)
        {
            operations = min(operations, best + gap[i]);
            best = min(best, gap[i - 1]);
        }
        cout << operations << endl;
    }
    return 0;
}