#include <iostream>
using namespace std;

bool valid(long long x)
{
    long long n = x;
    while (n > 0)
    {
        int d = n % 10;
        if (d > 0 && x % d != 0)
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        while (!valid(n))
            n++;
        cout << n << endl;
    }
    return 0;
}