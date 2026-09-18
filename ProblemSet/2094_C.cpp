#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n][n], p[2 * n];
        p[0] = n * (2 * n + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                p[i + j + 1] = a[i][j];
            }
        }
        for (int i = 1; i < 2 * n; i++)
            p[0] -= p[i];
        for (int i = 0; i < 2 * n; i++)
            cout << p[i] << " ";
        cout << endl;
    }
    return 0;
}