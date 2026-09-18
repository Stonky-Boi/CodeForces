#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }
        long long int total_pot = 0;
        int temp[n];
        for (int col = 0; col < m; col++)
        {
            for (int row = 0; row < n; ++row)
                temp[row] = a[row][col];
            sort(temp, temp + n);
            long long int prefix_sum = 0;
            for (int i = 0; i < n; ++i)
            {
                total_pot += 1LL * temp[i] * i - prefix_sum;
                prefix_sum += temp[i];
            }
        }
        cout << total_pot << endl;
    }
    return 0;
}