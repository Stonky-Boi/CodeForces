#include <iostream>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, a, b;
        cin >> l >> a >> b;
        int gcd_value = gcd(l, b);
        int max_prize = a + gcd_value * ((l - 1 - a) / gcd_value);
        cout << max_prize << endl;
    }
    return 0;
}