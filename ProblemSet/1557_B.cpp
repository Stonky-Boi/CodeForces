#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto &i : a)
            cin >> i;
        vector<long long> b = a;
        sort(b.begin(), b.end());
        map<long long, int> rank;
        for (int i = 0; i < n; i++)
            rank[b[i]] = i;
        int bad = 0;
        for (int i = 1; i < n; i++)
        {
            if (rank[a[i]] != rank[a[i - 1]] + 1)
                bad++;
        }
        cout << (bad <= k - 1 ? "YES" : "NO") << endl;
    }
    return 0;
}