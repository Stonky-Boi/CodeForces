#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long A = a, B = b;
        while (A % 2 == 0)
            A /= 2;
        while (B % 2 == 0)
            B /= 2;
        if (A != B)
        {
            cout << -1 << endl;
            continue;
        }
        a /= A;
        b /= B;
        A = log2(a);
        B = log2(b);
        cout << (abs(A - B) + 2) / 3 << endl;
    }
    return 0;
}