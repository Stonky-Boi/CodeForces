#include <iostream>
#include <vector>
using namespace std;

struct color
{
    int last = -1;
    int max1 = 0, max2 = 0;

    void add(int gap)
    {
        if (gap > max1)
        {
            max2 = max1;
            max1 = gap;
        }
        else if (gap > max2)
            max2 = gap;
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
        vector<int> c(n);
        vector<color> colors(k + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            color &x = colors[c[i]];
            x.add(i - x.last - 1);
            x.last = i;
        }
        int planks = n;
        for (color &x : colors)
        {
            if (x.last == -1)
                continue;
            x.add(n - x.last - 1);
            planks = min(planks, max(x.max1 / 2, x.max2));
        }
        cout << planks << endl;
    }
    return 0;
}