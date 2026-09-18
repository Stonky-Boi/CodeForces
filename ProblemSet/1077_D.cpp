#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    int l = 1, r = n;
    int best_m = 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        long long count = 0;
        for (auto [_, cnt] : freq)
            count += cnt / m;
        if (count >= k)
        {
            best_m = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    vector<int> t;
    for (auto [value, cnt] : freq)
    {
        int times = cnt / best_m;
        for (int j = 0; j < times && (int)t.size() < k; j++)
            t.push_back(value);
    }
    for (int x : t)
        cout << x << " ";
    cout << endl;
    return 0;
}