#include <iostream>
using namespace std;

bool possible(long int n, long int m)
{
    if (n == m)
        return true;
    if (n < m)
        return false;
    if (n % 3 == 0)
        return possible(n / 3, m) || possible(2 * n / 3, m);
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, m;
        cin >> n >> m;
        if (possible(n, m))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}