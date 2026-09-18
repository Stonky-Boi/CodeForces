#include <iostream>
using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int drink = (l * k) / nl;
    int lime = c * d;
    int salt = p / np;
    int toast = min(min(drink, lime), salt);
    cout << toast / n << endl;
    return 0;
}