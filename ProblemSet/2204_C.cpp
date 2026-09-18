#include <iostream>
#include <numeric>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, m;
        cin >> a >> b >> c >> m;

        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);

        long long all_three = m / abc;

        long long ab_only = m / ab - all_three;
        long long ac_only = m / ac - all_three;
        long long bc_only = m / bc - all_three;

        long long a_only = m / a - ab_only - ac_only - all_three;
        long long b_only = m / b - ab_only - bc_only - all_three;
        long long c_only = m / c - ac_only - bc_only - all_three;

        long long alice = 6 * a_only + 3 * (ab_only + ac_only) + 2 * all_three;
        long long bob = 6 * b_only + 3 * (ab_only + bc_only) + 2 * all_three;
        long long carol = 6 * c_only + 3 * (ac_only + bc_only) + 2 * all_three;

        cout << alice << " " << bob << " " << carol << endl;
    }
    return 0;
}