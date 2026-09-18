#include <iostream>
#include <vector>
using namespace std;

struct query
{
    int type;
    int x, y;
};

int main()
{
    int q;
    cin >> q;
    vector<query> queries(q);
    for (auto &qu : queries)
    {
        cin >> qu.type;
        if (qu.type == 1)
        {
            cin >> qu.x;
            qu.y = 0;
        }
        else
            cin >> qu.x >> qu.y;
    }
    const int max_queries = 500000;
    vector<int> to(max_queries + 1);
    for (int i = 1; i <= max_queries; i++)
        to[i] = i;
    vector<int> array;
    array.reserve(q);
    for (int i = q - 1; i >= 0; i--)
    {
        if (queries[i].type == 1)
            array.push_back(to[queries[i].x]);
        else
        {
            int x = queries[i].x;
            int y = queries[i].y;
            to[x] = to[y];
        }
    }
    for (int i = array.size() - 1; i >= 0; i--)
        cout << array[i] << (i == 0 ? '\n' : ' ');
    return 0;
}