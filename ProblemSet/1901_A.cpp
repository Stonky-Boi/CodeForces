#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n + 2];
        a[0] = 0;
        a[n + 1] = x;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int volume = 0;
        for (int i = 1; i < n + 2; i++)
            volume = max(volume, a[i] - a[i - 1]);
        volume = max(volume, 2 * (x - a[n]));
        cout << volume << endl;
    }
    return 0;
}