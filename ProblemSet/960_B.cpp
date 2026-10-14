#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    int k = k1 + k2;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        pq.push(abs(a[i] - b[i]));
    while (k > 0)
    {
        int x = pq.top();
        pq.pop();
        if (x == 0)
            break;
        x--;
        k--;
        pq.push(x);
    }
    long long value = k % 2;
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        value += 1ll * x * x;
    }
    cout << value << endl;
    return 0;
}