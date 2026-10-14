#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long window = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        window += a[i];
        if (i >= k)
            window -= a[i - k];
        if (i >= k - 1)
            sum += window;
    }
    cout << fixed << setprecision(10) << 1.0 * sum / (n - k + 1) << endl;
    return 0;
}