#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, d, h;
        cin >> n >> d >> h;
        long int y[n];
        for (int i = 0; i < n; i++)
            cin >> y[i];
        long double area = n * h * d * 0.5L;
        for (int i = 0; i < n - 1; i++)
        {
            if (h > y[i + 1] - y[i])
                area -= (h - y[i + 1] + y[i]) * (h - y[i + 1] + y[i]) * d / (2.0L * h);
        }
        cout << fixed << setprecision(10) << area << endl;
    }
    return 0;
}