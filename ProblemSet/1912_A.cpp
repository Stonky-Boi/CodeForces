#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct block
{
    long long sum, minimum;
};

struct node
{
    long long minimum;
    int index, position;

    bool operator<(const node &other) const
    {
        return minimum < other.minimum;
    }
};

int main()
{
    long long x;
    int k;
    cin >> x >> k;
    vector<vector<block>> a(k);
    for (int i = 0; i < k; i++)
    {
        int l;
        cin >> l;
        long long sum = 0, minimum = 0;
        for (int j = 0; j < l; j++)
        {
            long long v;
            cin >> v;
            sum += v;
            minimum = min(minimum, sum);
            if (sum > 0)
            {
                a[i].push_back({sum, minimum});
                sum = 0;
                minimum = 0;
            }
        }
    }
    priority_queue<node> pq;
    for (int i = 0; i < k; i++)
    {
        if (!a[i].empty())
            pq.push({a[i][0].minimum, i, 0});
    }
    while (!pq.empty())
    {
        node curr = pq.top();
        pq.pop();
        if (x + curr.minimum < 0)
            break;
        x += a[curr.index][curr.position].sum;
        int next = curr.position + 1;
        if (next < a[curr.index].size())
            pq.push({a[curr.index][next].minimum, curr.index, next});
    }
    cout << x << endl;
    return 0;
}