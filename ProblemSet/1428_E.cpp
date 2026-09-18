#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long cost(int a, int p)
{
    long long q = a / p;
    long long r = a % p;
    return r * (q + 1) * (q + 1) + (p - r) * q * q;
}

struct carrot
{
    int a;
    int pieces;
};

struct option
{
    long long saving;
    int index;

    bool operator<(const option &other) const
    {
        return saving < other.saving;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<carrot> carrots(n);
    for (auto &[a, pieces] : carrots)
    {
        cin >> a;
        pieces = 1;
    }
    priority_queue<option> pq;
    for (int i = 0; i < n; i++)
    {
        long long saving = cost(carrots[i].a, 1) - cost(carrots[i].a, 2);
        pq.push({saving, i});
    }
    for (int step = 0; step < k - n; step++)
    {
        option curr = pq.top();
        pq.pop();
        int i = curr.index;
        carrots[i].pieces++;
        int p = carrots[i].pieces;
        if (p < carrots[i].a)
        {
            long long saving = cost(carrots[i].a, p) - cost(carrots[i].a, p + 1);
            pq.push({saving, i});
        }
    }
    long long time = 0;
    for (const auto &[a, pieces] : carrots)
        time += cost(a, pieces);
    cout << time << endl;
    return 0;
}