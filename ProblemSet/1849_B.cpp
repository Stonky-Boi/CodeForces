#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct monster
{
    int index;
    int health;

    bool operator>(const monster &other) const
    {
        if (health == other.health)
            return index < other.index;
        return health > other.health;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<monster> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i].index = i + 1;
            cin >> a[i].health;
            a[i].health %= k;
            if (a[i].health == 0)
                a[i].health = k;
        }
        sort(a.begin(), a.end(), greater<monster>());
        for (const auto &[i, _] : a)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}