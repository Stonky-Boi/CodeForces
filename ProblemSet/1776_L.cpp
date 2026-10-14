#include <iostream>
using namespace std;

int main()
{
    int n, q;
    string s;
    cin >> n >> s >> q;
    int plus = 0, minus = 0;
    for (const char &c : s)
    {
        if (c == '+')
            plus++;
        else
            minus++;
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        int d = a - b;
        if (d == 0)
        {
            cout << (plus == minus ? "YES" : "NO") << endl;
            continue;
        }
        long long num = 1ll * (minus - plus) * b;
        if (num % d == 0)
        {
            long long k = num / d;
            cout << (k >= -minus && k <= plus ? "YES" : "NO") << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}