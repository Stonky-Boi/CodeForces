#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int MAXN = 1e6;
    vector<int> spf(MAXN + 1, 0); // smallest prime factor
    for (int i = 2; i <= MAXN; i++)
    {
        if (spf[i] == 0)
        {
            for (int j = i; j <= MAXN; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            while (a[i] > 1)
            {
                int p = spf[a[i]];
                freq[p]++;
                a[i] /= p;
            }
        }
        bool possible = true;
        for (const auto &[_, f] : freq)
        {
            if (f % n != 0)
            {
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}