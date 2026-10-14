#include <iostream>
using namespace std;

int xor_value(int n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int value = xor_value(a - 1);
        cout << a + (value == b ? 0 : ((value ^ b) == a ? 2 : 1)) << endl;
    }
    return 0;
}