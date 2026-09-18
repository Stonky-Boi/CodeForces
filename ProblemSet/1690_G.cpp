#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (auto &i : a)
            cin >> i;
        set<int> records;
        long long minimum = (1ll << 60);
        for (int i = 0; i < n; i++)
        {
            if (a[i] < minimum)
            {
                records.insert(i);
                minimum = a[i];
            }
        }
        while (m--)
        {
            int k;
            long long d;
            cin >> k >> d;
            a[--k] -= d;
            auto it = records.lower_bound(k);
            long long prev_min = (it != records.begin() ? a[*(--it)] : (1ll << 60));
            if (a[k] < prev_min)
            {
                records.insert(k);
                auto curr = records.find(k);
                curr++;
                while (curr != records.end() && a[*curr] >= a[k])
                    curr = records.erase(curr);
            }
            cout << records.size() << ' ';
        }
        cout << endl;
    }
    return 0;
}