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
        vector<long long> b(n);
        for (long long &i : b)
            cin >> i;
        vector<long long> prefix(n), suffix(n);
        prefix[0] = b[0];
        for (int i = 1; i < n; i++)
            prefix[i] = max(prefix[i - 1], b[i] + i);
        suffix[n - 1] = b[n - 1] - (n - 1);
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = max(suffix[i + 1], b[i] - i);
        long long value = 0;
        for (int i = 1; i < n - 1; i++)
            value = max(value, prefix[i - 1] + b[i] + suffix[i + 1]);
        cout << value << endl;
    }
    return 0;
}