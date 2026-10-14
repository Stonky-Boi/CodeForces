#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> last(n, -1);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if (x > y)
                swap(x, y);
            last[y] = max(last[y], x);
        }
        long long good = 0;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            i = max(i, last[j] + 1);
            good += j - i + 1;
        }
        cout << good << endl;
    }
    return 0;
}