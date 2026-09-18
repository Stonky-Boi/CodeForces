#include <iostream>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int main()
{
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    int g = gcd(a, c);
    if ((d - b) % g != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    long long rick = b, morty = d;
    while (rick != morty)
    {
        if (rick < morty)
            rick += a;
        else
            morty += c;
    }
    cout << rick << endl;
    return 0;
}