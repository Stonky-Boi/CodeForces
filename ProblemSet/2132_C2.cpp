#include <iostream>
using namespace std;

int main()
{
    const int size = 18;
    vector<long long> melon(size + 2), cost(size + 2);
    melon[0] = 1;
    for (int x = 1; x <= size + 1; x++)
        melon[x] = melon[x - 1] * 3;
    cost[0] = 3;
    for (int x = 1; x <= size; x++)
        cost[x] = melon[x + 1] + 1LL * x * melon[x - 1];
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<int> count(size + 2, 0);
        int i = 0;
        long long deals = 0, total_cost = 0;
        while (n > 0)
        {
            int d = n % 3;
            count[i] = d;
            deals += d;
            total_cost += 1LL * d * cost[i];
            n /= 3;
            i++;
        }
        if (deals > k)
        {
            cout << -1 << endl;
            continue;
        }
        long long extra_deals = k - deals;
        for (int j = size; j >= 1 && extra_deals >= 2; j--)
        {
            if (count[j] == 0)
                continue;
            long long splits = min<long long>(count[j], extra_deals / 2);
            if (splits > 0)
            {
                total_cost -= splits * melon[j - 1];
                extra_deals -= 2 * splits;
                count[j] -= splits;
                count[j - 1] += 3 * splits;
            }
        }
        cout << total_cost << endl;
    }
    return 0;
}