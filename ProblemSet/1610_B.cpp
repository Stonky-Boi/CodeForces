#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &a, int n, int x)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (a[l] == x)
            l++;
        else if (a[r] == x)
            r--;
        else
        {
            if (a[l] != a[r])
                return false;
            l++;
            r--;
        }
    }
    return true;
}

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
        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != a[n - i - 1])
            {
                possible = check(a, n, a[i]) || check(a, n, a[n - i - 1]);
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}