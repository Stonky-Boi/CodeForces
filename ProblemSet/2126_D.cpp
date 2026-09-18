#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        long long int k;
        cin >> n >> k;
        pair<pair<long long int, long long int>, long long int> casinos[n];
        for (int i = 0; i < n; i++)
            cin >> casinos[i].first.first >> casinos[i].first.second >> casinos[i].second;
        sort(casinos, casinos + n);
        long long int coins = k;
        for (int i = 0; i < n; i++)
        {
            if (casinos[i].first.first > coins)
                break;
            coins = max(coins, casinos[i].second);
        }
        cout << coins << endl;
    }
    return 0;
}