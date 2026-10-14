#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool valid(vector<int> &a, vector<int> &b, int n, int operations)
{
    for (int i = 0; i < n - operations; i++)
    {
        if (a[i] >= b[operations + i])
            return false;
    }
    return true;
}

int min_operations(int x, vector<int> a, vector<int> &b, int n)
{
    a[0] = x;
    sort(a.begin(), a.end());
    int operations;
    int left = 0, right = n;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (valid(a, b, n, mid))
        {
            operations = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return operations;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        a[0] = 1;
        for (int i = 1; i < n; i++)
            cin >> a[i];
        for (int &i : b)
            cin >> i;
        sort(b.begin(), b.end());
        int base = min_operations(1, a, b, n);
        int left = 1, right = m;
        int position = m + 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int curr = min_operations(mid, a, b, n);
            if (curr == base)
                left = mid + 1;
            else
            {
                position = mid;
                right = mid - 1;
            }
        }
        long long sum = 1ll * (position - 1) * base + 1ll * (m - position + 1) * (base + 1);
        cout << sum << endl;
    }
    return 0;
}