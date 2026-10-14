#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n % 2 == 1 || n == 2)
            cout << -1 << endl;
        else
        {
            long long x = (n + 5) / 6;
            long long y = n / 4;
            cout << x << " " << y << endl;
        }
    }
    return 0;
}