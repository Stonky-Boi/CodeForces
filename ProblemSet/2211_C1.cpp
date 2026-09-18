#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        bool possible = true;
        vector<bool> in_s(n + 1, false), seen(n + 1, false);
        for (int i = n - k; i < k; ++i)
            in_s[a[i]] = true;
        for (int i = 0; i < n; ++i)
        {
            if (i < n - k || i >= k)
            {
                if (b[i] != -1 && b[i] != a[i])
                {
                    possible = false;
                    break;
                }
            }
            else
            {
                if (b[i] != -1)
                {
                    if (!in_s[b[i]] || seen[b[i]])
                    {
                        possible = false;
                        break;
                    }
                    seen[b[i]] = true;
                }
            }
        }
        cout << ((possible) ? "YES" : "NO") << endl;
    }
    return 0;
}