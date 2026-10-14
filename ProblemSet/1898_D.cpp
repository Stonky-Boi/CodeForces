#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        long long beauty = 0;
        int max_value = 0, min_value = 1e9;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
                swap(a[i], b[i]);
            beauty += b[i] - a[i];
            max_value = max(max_value, a[i]);
            min_value = min(min_value, b[i]);
        }
        beauty += 2ll * max(0, max_value - min_value);
        cout << beauty << endl;
    }
    return 0;
}