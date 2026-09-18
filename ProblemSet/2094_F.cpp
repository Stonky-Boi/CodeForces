#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, m, k;
        cin >> n >> m >> k;
        long int repetition = n * m / k, a[n][m];
        int digit = 1;
        if (n % k == 0)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    a[i][j] = (digit + (i + j) % k) % k + 1;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    a[i][j] = digit;
                    digit = (digit % k) + 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}