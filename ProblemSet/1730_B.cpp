#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> x(n), t(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> t[i];
        int min_value = 1e9;
        int max_value = -1e9;
        for (int i = 0; i < n; i++)
        {
            min_value = min(min_value, x[i] - t[i]);
            max_value = max(max_value, x[i] + t[i]);
        }
        int x0 = min_value + max_value;
        cout << x0 / 2;
        if (x0 % 2 != 0)
            cout << ".5";
        cout << endl;
    }
    return 0;
}