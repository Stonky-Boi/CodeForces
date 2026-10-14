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
        int d = n;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i <= k)
                    d = min(d, n / i);
                if (n / i <= k)
                    d = min(d, i);
            }
        }
        cout << d << endl;
    }
    return 0;
}