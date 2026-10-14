#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inversion_parity(vector<int> &a)
{
    int n = a.size();
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    vector<int> bit(n + 1, 0);
    int parity = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int rank = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin() + 1;
        for (int j = rank - 1; j > 0; j -= j & -j)
            parity ^= bit[j] & 1;
        for (int j = rank; j <= n; j += j & -j)
            bit[j]++;
    }
    return parity;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        vector<int> sorted_a = a, sorted_b = b;
        sort(sorted_a.begin(), sorted_a.end());
        sort(sorted_b.begin(), sorted_b.end());
        if (sorted_a != sorted_b)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << (inversion_parity(a) == inversion_parity(b) ? "YES" : "NO") << endl;
    }
    return 0;
}