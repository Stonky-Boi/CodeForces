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
        vector<string> a(n);
        for (string &i : a)
            cin >> i;
        int operations = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ones = (a[i][j] - '0') + (a[j][n - i - 1] - '0') + (a[n - i - 1][n - j - 1] - '0') + (a[n - j - 1][i] - '0');
                operations += min(ones, 4 - ones);
            }
        }
        operations /= 4;
        cout << operations << endl;
    }
    return 0;
}