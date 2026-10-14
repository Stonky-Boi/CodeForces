#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool valid(vector<int> &a, int n, int k, int target)
{
    for (int i = 0; i < n; i++)
    {
        int operations = 0;
        int need = target;
        for (int j = i; j < n; j++)
        {
            if (a[j] >= need)
                break;
            if (j == n - 1)
            {
                operations = 1e9;
                break;
            }
            operations += need - a[j];
            need--;
            if (operations > k)
                break;
        }
        if (operations <= k)
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int max_value = 0;
        for (int &i : a)
        {
            cin >> i;
            max_value = max(max_value, i);
        }
        int l = max_value;
        int r = max_value + n;
        int maximum = max_value;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (valid(a, n, k, m))
            {
                maximum = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        cout << maximum << endl;
    }
    return 0;
}