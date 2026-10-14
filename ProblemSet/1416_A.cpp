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
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<int> last(n + 1, -1);
        vector<int> gap(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            gap[x] = max(gap[x], i - last[x]);
            last[x] = i;
        }
        for (int x = 1; x <= n; x++)
        {
            if (last[x] != -1)
                gap[x] = max(gap[x], n - last[x]);
        }
        vector<int> amazing(n + 1, -1);
        for (int x = 1; x <= n; x++)
        {
            if (last[x] == -1)
                continue;
            for (int k = gap[x]; k <= n; k++)
            {
                if (amazing[k] != -1)
                    break;
                amazing[k] = x;
            }
        }
        for (int k = 1; k <= n; k++)
            cout << amazing[k] << ' ';
        cout << endl;
    }
    return 0;
}