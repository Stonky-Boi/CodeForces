#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> freq;
        for (int &i : a)
        {
            cin >> i;
            int r = i % k;
            if (r != 0)
                freq[k - r]++;
        }
        long long moves = 0;
        for (const auto &[need, count] : freq)
        {
            long long last = need + 1ll * (count - 1) * k;
            moves = max(moves, last + 1);
        }
        cout << moves << endl;
    }
    return 0;
}