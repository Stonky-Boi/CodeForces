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
        vector<int> l(n + 1), r(n + 1), u(n + 1), v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> l[i] >> r[i] >> u[i] >> v[i];
        int length = 0;
        for (int m = n; m >= 1; m--)
        {
            int j = 1;
            for (int i = 1; i <= n && j <= m; i++)
            {
                int k = m - j + 1;
                if ((l[i] > j || j > r[i]) && (u[i] > k || k > v[i]))
                    j++;
            }
            if (j != m + 1)
                continue;
            length = m;
            break;
        }
        cout << length << endl;
    }
    return 0;
}