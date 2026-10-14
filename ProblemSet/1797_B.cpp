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
        vector<vector<int>> a(n, vector<int>(n));
        for (vector<int> &v : a)
        {
            for (int &i : v)
                cin >> i;
        }
        int operations = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] != a[n - i - 1][n - j - 1])
                    operations++;
            }
        }
        operations /= 2;
        bool possible = operations <= k && (n % 2 == 1 || (k - operations) % 2 == 0);
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}