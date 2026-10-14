#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct resident
{
    int a;
    int b;

    bool operator<(const resident &other) const
    {
        if (b == other.b)
            return a > other.a;
        return b < other.b;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        vector<resident> r(n);
        for (resident &i : r)
            cin >> i.a;
        for (resident &i : r)
            cin >> i.b;
        r.push_back({n, p});
        sort(r.begin(), r.end());
        long long cost = p;
        n--;
        for (const auto &[a, b] : r)
        {
            if (a >= n)
            {
                cost += 1ll * n * b;
                break;
            }
            n -= a;
            cost += 1ll * a * b;
        }
        cout << cost << endl;
    }
    return 0;
}