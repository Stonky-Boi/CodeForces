#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long x[n], v[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    double l = 0.0, r = 1e9;
    for (int iter = 0; iter < 100; iter++)
    {
        double m = (l + r) / 2.0;
        double L = -1e18, R = 1e18;
        for (int i = 0; i < n; i++)
        {
            double left = x[i] - v[i] * m;
            double right = x[i] + v[i] * m;
            if (left > L)
                L = left;
            if (right < R)
                R = right;
        }
        if (L <= R)
            r = m;
        else
            l = m;
    }
    cout << fixed << setprecision(7) << r << endl;
    return 0;
}