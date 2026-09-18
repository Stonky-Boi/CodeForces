#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(n), b(m);
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        vector<bool> seen(n + 1, false);
        int i = 0;
        bool good = true;
        for (int x : b)
        {
            if (seen[x])
                continue;
            if (i >= n || x != a[i])
            {
                good = false;
                break;
            }
            seen[x] = true;
            i++;
        }
        cout << (good ? "YA" : "TIDAK") << endl;
    }
    return 0;
}