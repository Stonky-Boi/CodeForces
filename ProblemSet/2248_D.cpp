#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        vector<int> prefix_a(n + 1, 0), prefix_b(n + 1, 0);
        vector<int> prefix_match(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix_a[i + 1] = prefix_a[i] + (a[i] == '1');
            prefix_b[i + 1] = prefix_b[i] + (b[i] == '1');
            prefix_match[i + 1] = prefix_match[i] + (a[i] == b[i]);
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int one_a = prefix_a[r] - prefix_a[l - 1];
            int one_b = prefix_b[r] - prefix_b[l - 1];
            int match = prefix_match[r] - prefix_match[l - 1];
            cout << (abs(one_a - one_b) <= match ? "YES" : "NO") << endl;
        }
    }
    return 0;
}