#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        long int a[n], prefix_min[n], suffix_max[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        prefix_min[0] = a[0];
        for (int i = 1; i < n; i++)
            prefix_min[i] = min(prefix_min[i - 1], a[i]);
        suffix_max[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix_max[i] = max(suffix_max[i + 1], a[i]);
        string possibility(n, '0');
        for (int i = 0; i < n; i++)
        {
            if (a[i] == prefix_min[i] || a[i] == suffix_max[i])
                possibility[i] = '1';
        }
        cout << possibility << endl;
    }
    return 0;
}