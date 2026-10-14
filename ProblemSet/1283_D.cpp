#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    set<int> used;
    vector<int> x(n);
    for (int &i : x)
    {
        cin >> i;
        used.insert(i);
        q.push({i, 0});
    }
    vector<int> y;
    long long res = 0;
    while (y.size() < m)
    {
        auto [x, d] = q.front();
        q.pop();
        for (int next : {x - 1, x + 1})
        {
            if (used.find(next) == used.end())
            {
                used.insert(next);
                y.push_back(next);
                res += d + 1;
                q.push({next, d + 1});
                if (y.size() == m)
                    break;
            }
        }
        if (y.size() == m)
            break;
    }
    cout << res << endl;
    for (const int &i : y)
        cout << i << " ";
    cout << endl;
    return 0;
}