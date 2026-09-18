#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], candy_1 = 0, candy_2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                candy_1++;
            else
                candy_2++;
        }
        int candy_weight = candy_1 + candy_2 * 2;
        if (candy_weight % 2 == 0)
        {
            int candy_set = candy_weight / 2;
            candy_set -= min(candy_set / 2, candy_2) * 2;
            if (candy_set <= candy_1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}