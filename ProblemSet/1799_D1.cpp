#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<long long> cold(k + 1), hot(k + 1);
        for (int i = 1; i <= k; i++)
            cin >> cold[i];
        for (int i = 1; i <= k; i++)
            cin >> hot[i];
        vector<long long> curr(k + 1, INF);
        curr[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            int y = (i == 0 ? 0 : a[i - 1]);
            vector<long long> next(k + 1, INF);
            long long cost = (x == y ? hot[x] : cold[x]);
            for (int j = 0; j <= k; j++)
                next[j] = min(next[j], curr[j] + cost);
            for (int j = 0; j <= k; j++)
            {
                long long cost = (j == x ? hot[x] : cold[x]);
                next[y] = min(next[y], curr[j] + cost);
            }
            curr = next;
        }
        cout << *min_element(curr.begin(), curr.end()) << endl;
    }
    return 0;
}