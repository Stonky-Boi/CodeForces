#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long max_even = 0, min_odd = LLONG_MAX;
        for (int i = 1; i <= n; i++)
        {
            long long w;
            cin >> w;
            if (i % 2 == 0)
                max_even = max(max_even, w);
            else
                min_odd = min(min_odd, w);
        }
        cout << (n % 2 == 0 && max_even + 2 <= min_odd ? "YES" : "NO") << endl;
    }
    return 0;
}