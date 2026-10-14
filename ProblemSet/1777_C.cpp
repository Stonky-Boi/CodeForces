#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int MAX_A = 1e5;
    vector<int> factors[MAX_A + 1];
    for (int i = 1; i <= MAX_A; i++)
    {
        for (int j = i; j <= MAX_A; j += i)
            factors[j].push_back(i);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        vector<int> freq(m + 1, 0);
        int covered = 0;
        int j = 0;
        int difference = 1e9;
        for (int i = 0; i < n; i++)
        {
            while (j < n && covered < m)
            {
                for (int f : factors[a[j]])
                {
                    if (f > m)
                        break;
                    freq[f]++;
                    if (freq[f] == 1)
                        covered++;
                }
                j++;
            }
            if (covered == m)
                difference = min(difference, a[j - 1] - a[i]);
            for (int f : factors[a[i]])
            {
                if (f > m)
                    break;
                freq[f]--;
                if (freq[f] == 0)
                    covered--;
            }
            if (j == n && covered < m)
                break;
        }
        cout << (difference == 1e9 ? -1 : difference) << endl;
    }
    return 0;
}