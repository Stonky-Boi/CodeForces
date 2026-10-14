#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bool possible = false;
        int A = 2 * b - c;
        possible = A >= a && A % a == 0;
        if (!possible)
        {
            int B = (a + c) / 2;
            possible = (a + c) % 2 == 0 && B >= b && B % b == 0;
        }
        if (!possible)
        {
            int C = 2 * b - a;
            possible = C >= c && C % c == 0;
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}