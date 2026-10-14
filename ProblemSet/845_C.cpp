#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r + 1, -1});
    }
    sort(events.begin(), events.end());
    bool possible = true;
    int televisions = 0;
    for (const auto &[_, i] : events)
    {
        televisions += i;
        if (televisions > 2)
        {
            possible = false;
            break;
        }
    }
    cout << (possible ? "YES" : "NO") << endl;
    return 0;
}