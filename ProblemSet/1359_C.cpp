#include <iostream>
using namespace std;

long long abs_diff(long long a, long long b)
{
    return (a > b) ? (a - b) : (b - a);
}

pair<long long, long long> evaluate(long long k, long long h, long long c, long long t)
{
    long long denominator = 2 * k + 1;
    long long numerator = (k + 1) * h + k * c;
    long long difference = abs_diff(numerator, t * denominator);
    return {denominator, difference};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long h, c, temp;
        cin >> h >> c >> temp;
        if (temp == h)
        {
            cout << 1 << endl;
            continue;
        }
        if (2 * temp <= h + c)
        {
            cout << 2 << endl;
            continue;
        }
        long long k = (h - temp) / (2 * temp - h - c);
        auto [cups1, diff1] = evaluate(k, h, c, temp);
        auto [cups2, diff2] = evaluate(k + 1, h, c, temp);
        if (diff1 * cups2 <= diff2 * cups1)
            cout << cups1 << endl;
        else
            cout << cups2 << endl;
    }
    return 0;
}