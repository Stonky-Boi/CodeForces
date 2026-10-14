#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct element
{
    int value;
    int index;

    bool operator<(const element &other) const
    {
        return value < other.value;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<element> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].value;
            a[i].index = i + 1;
        }
        sort(a.begin(), a.end());
        int pairs = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (1ll * a[i].value * a[j].value >= 2 * n)
                    break;
                if (a[i].value * a[j].value == a[i].index + a[j].index)
                    pairs++;
            }
        }
        cout << pairs << endl;
    }
    return 0;
}