#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        int lcs = 0;
        for (int l = 1; l <= min(n, m); l++)
        {
            for (int i = 0; i + l - 1 < n; i++)
            {
                for (int j = 0; j + l - 1 < m; j++)
                {
                    if (a.substr(i, l) == b.substr(j, l))
                        lcs = max(lcs, l);
                }
            }
        }
        cout << n + m - 2 * lcs << endl;
    }
    return 0;
}