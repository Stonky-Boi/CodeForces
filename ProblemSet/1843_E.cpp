#include <iostream>
#include <vector>
using namespace std;

struct segment
{
    int l, r;
};

bool valid(vector<segment> &s, vector<int> &queries, int n, int k)
{
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < k; i++)
        prefix[queries[i]] = 1;
    for (int i = 1; i <= n; i++)
        prefix[i] += prefix[i - 1];
    for (const auto &[l, r] : s)
    {
        int ones = prefix[r] - prefix[l - 1];
        int length = r - l + 1;
        if (ones * 2 > length)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m;
        vector<segment> s(m);
        for (auto &[l, r] : s)
            cin >> l >> r;
        cin >> q;
        vector<int> queries(q);
        for (int &i : queries)
            cin >> i;
        int left = 1, right = q;
        int first = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (valid(s, queries, n, mid))
            {
                first = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        cout << first << endl;
    }
    return 0;
}