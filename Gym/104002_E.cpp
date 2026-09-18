#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (auto &x : a)
        cin >> x;
    // pq stores integers picked
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
        if (i & 1)
            pq.pop();
    }
    long long score = 0;
    while (!pq.empty())
    {
        score += pq.top();
        pq.pop();
    }
    cout << score << endl;
    return 0;
}