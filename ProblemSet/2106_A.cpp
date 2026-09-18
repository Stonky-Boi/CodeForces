#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, count_one = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                count_one++;
        }
        int sum = n * count_one + n - 2 * count_one;
        cout << sum << endl;
    }
    return 0;
}