#include <iostream>
#include <vector>
using namespace std;

struct problem
{
    int a, b;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<problem> v(n);
        vector<int> topic(n + 1, 0), difficulty(n + 1, 0);
        for (auto &[a, b] : v)
        {
            cin >> a >> b;
            topic[a]++;
            difficulty[b]++;
        }
        long long total = 1ll * n * (n - 1) * (n - 2) / 6;
        long long bad = 0;
        for (const auto &[a, b] : v)
            bad += 1ll * (topic[a] - 1) * (difficulty[b] - 1);
        cout << total - bad << endl;
    }
    return 0;
}