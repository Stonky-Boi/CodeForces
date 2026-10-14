#include <iostream>
#include <vector>
using namespace std;

struct city
{
    long long x, y;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        a--;
        b--;
        vector<city> cities(n);
        for (auto &[x, y] : cities)
            cin >> x >> y;
        long long price = abs(cities[a].x - cities[b].x) + abs(cities[a].y - cities[b].y);
        long long min_a = 1e18, min_b = 1e18;
        for (int i = 0; i < k; i++)
        {
            min_a = min(min_a, abs(cities[a].x - cities[i].x) + abs(cities[a].y - cities[i].y));
            min_b = min(min_b, abs(cities[i].x - cities[b].x) + abs(cities[i].y - cities[b].y));
        }
        price = min(price, min_a + min_b);
        cout << price << endl;
    }
    return 0;
}