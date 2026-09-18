#include <iostream>
using namespace std;

bool is_prime(long long int x)
{
    if (x <= 1)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    for (long long i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int x;
        int k;
        cin >> x >> k;
        if (k == 1 && is_prime(x))
            cout << "YES" << endl;
        else if (x == 1 && k == 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}