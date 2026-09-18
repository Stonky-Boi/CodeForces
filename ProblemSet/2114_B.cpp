#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int zero_count = 0, one_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                zero_count++;
            else
                one_count++;
        }
        int max_pairs = n / 2;
        int zeros_needed_for_bad = max_pairs - k;
        if (zero_count < zeros_needed_for_bad || one_count < zeros_needed_for_bad)
        {
            cout << "NO" << endl;
            continue;
        }
        int max_x = (zero_count - zeros_needed_for_bad) / 2;
        int max_y = (one_count - zeros_needed_for_bad) / 2;
        if (max_x < 0 || max_y < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int low = max(0, k - max_y);
        int high = min(k, max_x);
        if (low <= high)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}