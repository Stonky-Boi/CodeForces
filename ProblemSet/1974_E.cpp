#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e18;

struct month
{
    int c, h;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, x;
        cin >> m >> x;
        vector<month> months(m);
        int total_happiness = 0;
        for (auto &[c, h] : months)
        {
            cin >> c >> h;
            total_happiness += h;
        }
        vector<long long> dp(total_happiness + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < m; i++)
        {
            int cost = months[i].c;
            int happiness = months[i].h;
            long long money = 1ll * i * x;
            for (int j = total_happiness - happiness; j >= 0; j--)
            {
                if (dp[j] == INF)
                    continue;
                if (dp[j] + cost <= money)
                    dp[j + happiness] = min(dp[j + happiness], dp[j] + cost);
            }
        }
        int sum = 0;
        for (int i = 0; i <= total_happiness; i++)
        {
            if (dp[i] != INF)
                sum = i;
        }
        cout << sum << endl;
    }
    return 0;
}