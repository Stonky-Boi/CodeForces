#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> dp(n, -1); // nearest element to the left that is different
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i > 0)
                dp[i] = a[i - 1] == a[i] ? dp[i - 1] : i - 1;
        }
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (dp[r] < l)
                cout << "-1 -1" << endl;
            else
                cout << dp[r] + 1 << " " << r + 1 << endl;
        }
        cout << endl;
    }
    return 0;
}