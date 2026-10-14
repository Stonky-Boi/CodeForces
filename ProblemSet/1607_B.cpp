#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, n;
        cin >> x >> n;
        long long d = 0;
        if (n % 4 == 1)
            d = -n;
        else if (n % 4 == 2)
            d = 1;
        else if (n % 4 == 3)
            d = n + 1;
        cout << x + (x % 2 == 0 ? d : -d) << endl;
    }
    return 0;
}