#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n > 1 && k == n - 1)
        {
            cout << -1 << endl;
            continue;
        }
        int blocks = n - k;
        int zero_count = (n + 1) / 2, one_count = n / 2;
        for (int i = 1; i <= blocks; i++)
        {
            if (i % 2 == 1)
            {
                if (i + 2 > blocks)
                    while (zero_count--)
                        cout << 0;
                else
                {
                    zero_count--;
                    cout << 0;
                }
            }
            else
            {
                if (i + 2 > blocks)
                    while (one_count--)
                        cout << 1;
                else
                {
                    one_count--;
                    cout << 1;
                }
            }
        }
        cout << endl;
    }
    return 0;
}