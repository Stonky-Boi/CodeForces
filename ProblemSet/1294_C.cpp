#include <iostream>
using namespace std;

int smallest_factor(int n, int start)
{
    for (int i = start; i * i <= n; i++)
    {
        if (n % i == 0)
            return i;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a = smallest_factor(n, 2);
        if (a == -1)
        {
            cout << "NO" << endl;
            continue;
        }
        n /= a;
        int b = smallest_factor(n, a + 1);
        if (b == -1)
        {
            cout << "NO" << endl;
            continue;
        }
        n /= b;
        int c = n;
        if (c <= b)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}