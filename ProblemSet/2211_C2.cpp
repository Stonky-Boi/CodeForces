#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        bool possible = true;
        vector<int> first_window(k, -1);
        for (int i = 0; i < k; ++i)
        {
            bool constant_values = true;
            for (int j = i + k; j < n; j += k)
            {
                if (a[j] != a[i])
                {
                    constant_values = false;
                    break;
                }
            }
            if (!constant_values)
            {
                for (int j = i; j < n; j += k)
                {
                    if (b[j] != -1 && b[j] != a[j])
                        possible = false;
                }
                first_window[i] = a[i];
            }
            else
            {
                int required_value = -1;
                for (int j = i; j < n; j += k)
                {
                    if (b[j] != -1)
                    {
                        if (required_value == -1)
                            required_value = b[j];
                        else if (required_value != b[j])
                            possible = false;
                    }
                }
                first_window[i] = required_value;
            }
        }
        if (possible)
        {
            vector<int> freq_a(n + 1, 0), freq_b(n + 1, 0);
            for (int i = 0; i < k; ++i)
            {
                freq_a[a[i]]++;
                if (first_window[i] != -1)
                    freq_b[first_window[i]]++;
            }
            for (int i = 1; i <= n; ++i)
            {
                if (freq_b[i] > freq_a[i])
                {
                    possible = false;
                    break;
                }
            }
        }
        cout << ((possible) ? "YES" : "NO") << endl;
    }
    return 0;
}