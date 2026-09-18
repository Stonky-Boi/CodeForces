#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, a, b;
        cin >> n >> a >> b;
        bool symmetric = false;
        if (a <= b)
            cout << ((n % 2) == (b % 2) ? "YES" : "NO") << endl;
        else
            cout << ((n % 2) == (b % 2) && (n % 2) == (a % 2) ? "YES" : "NO") << endl;
    }
    return 0;
}