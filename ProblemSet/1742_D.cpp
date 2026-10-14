#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> last(1001, -1);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            last[x] = i + 1;
        }
        int value = -1;
        for (int x = 1; x <= 1000; x++)
        {
            if (last[x] == -1)
                continue;
            for (int y = 1; y <= 1000; y++)
            {
                if (last[y] == -1)
                    continue;
                if (gcd(x, y) == 1)
                    value = max(value, last[x] + last[y]);
            }
        }
        cout << value << endl;
    }
    return 0;
}