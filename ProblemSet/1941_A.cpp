#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, ways = 0;
        cin >> n >> m >> k;
        int b[n], c[m];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < m; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (b[i] + c[j] <= k)
                    ways++;
            }
        }
        cout << ways << endl;
    }
    return 0;
}