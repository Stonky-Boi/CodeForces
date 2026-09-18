#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> bad;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        bad.insert({a, b});
    }
    vector<int> order;
    for (int x = 1; x <= n; x++)
    {
        order.push_back(x);
        int position = order.size() - 1;
        while (position > 0 && bad.count({order[position - 1], order[position]}))
        {
            swap(order[position - 1], order[position]);
            position--;
        }
    }
    for (int x : order)
        cout << x << ' ';
    cout << endl;
    return 0;
}