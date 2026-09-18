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
        long long n;
        cin >> n;
        long long total_cost = 0;
        int i = 0;
        while (n > 0)
        {
            int d = n % 3;
            total_cost += 1LL * d * cost[i];
            n /= 3;
            i++;
        }
        cout << total_cost << endl;
    }
    return 0;
}