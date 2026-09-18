#include <iostream>
using namespace std;

int main()
{
    long long int n, m, a;
    long long int r;
    cin >> n >> m >> a;
    int r1 = n / a;
    int r2 = m / a;
    if (n % a != 0)
        r1++;
    if (m % a != 0)
        r2++;
    r = r1 * r2;
    cout << r << endl;
    return 0;
}