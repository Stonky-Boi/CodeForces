#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person
{
    int x, y;

    bool operator>(const person &other) const
    {
        return y - x > other.y - other.x;
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
        vector<person> p(n);
        for (auto &[i, _] : p)
            cin >> i;
        for (auto &[_, i] : p)
            cin >> i;
        sort(p.begin(), p.end(), greater<person>());
        int days = 0;
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (p[l].y + p[r].y >= p[l].x + p[r].x)
            {
                l++;
                r--;
                days++;
            }
            else
                r--;
        }
        cout << days << endl;
    }
    return 0;
}