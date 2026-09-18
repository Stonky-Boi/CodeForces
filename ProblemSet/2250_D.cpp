#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int mod = 998244353;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1, 0);
        bool valid = true;
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == n)
                valid = false;
        }
        if (!valid)
        {
            cout << 0 << endl;
            continue;
        }
        vector<bool> prefix(n + 1, false), suffix(n + 2, false);
        prefix[0] = true;
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] && (a[i] >= a[i - 1]);
        suffix[n] = true;
        for (int i = n - 1; i >= 1; i--)
            suffix[i] = suffix[i + 1] && (a[i] >= a[i + 1]);
        long long count = 0;
        for (int cut = 0; cut < n; cut++)
        {
            if (!prefix[cut] || !suffix[cut + 1])
                continue;
            if (cut > 0 && cut < n - 1 && a[cut] == a[cut + 1])
                continue;
            vector<int> left, right;
            for (int i = 1; i <= cut; i++)
                left.push_back(a[i]);
            for (int i = cut + 1; i < n; i++)
                right.push_back(a[i]);
            reverse(right.begin(), right.end());
            vector<bool> visited(n + 1, false);
            int i = 0, j = 0;
            int used = 0;
            long long ways = 1;
            while (i < left.size() || j < right.size())
            {
                int value;
                if (i == left.size())
                    value = right[j++];
                else if (j == right.size())
                    value = left[i++];
                else if (left[i] < right[j])
                    value = left[i++];
                else if (left[i] > right[j])
                    value = right[j++];
                else
                {
                    valid = false;
                    break;
                }
                if (!visited[value])
                    visited[value] = true;
                else
                {
                    if (value < used)
                    {
                        ways = 0;
                        break;
                    }
                    ways = (ways * (value - used)) % mod;
                }
                used++;
            }
            if (!valid)
                break;
            count = (count + ways) % mod;
        }
        cout << (valid ? count : 0) << endl;
    }
    return 0;
}