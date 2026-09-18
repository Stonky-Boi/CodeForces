#include <iostream>
#include <vector>
using namespace std;

const int MOD = 676767677;

int count_divisors(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if (i * i != n)
                count++;
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int sum = x - y;
        int minimum;
        if (sum == 0)
            minimum = 1;
        else
            minimum = count_divisors(abs(sum)) % MOD;
        cout << minimum << endl;
        for (int i = 0; i < x; i++)
            cout << 1 << " ";
        for (int i = 0; i < y; i++)
            cout << -1 << " ";
        cout << endl;
    }
    return 0;
}