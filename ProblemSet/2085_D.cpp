#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long d[n];
        for (auto &i : d)
            cin >> i;
        int x = n / (k + 1);
        priority_queue<long long> pq;
        vector<int> must_take;
        for (int i = 1; i <= x; i++)
            must_take.push_back(n - i * (k + 1) + 1);
        int take_index = (int)must_take.size() - 1;
        long long deliciousness = 0;
        for (int i = 1; i <= n; i++)
        {
            pq.push(d[i - 1]);
            if (take_index >= 0 && i == must_take[take_index])
            {
                deliciousness += pq.top();
                pq.pop();
                take_index--;
            }
        }
        cout << deliciousness << endl;
    }
    return 0;
}