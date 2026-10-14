#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<int> a(n), f(n);
        vector<int> freq(n + 1, 0), good(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> f[i];
            freq[a[i]]++;
            if (f[i] == 1)
                good[a[i]]++;
        }
        vector<vector<int>> total_freq(n + 1);
        for (int type = 1; type <= n; type++)
        {
            if (freq[type] > 0)
                total_freq[freq[type]].push_back(type);
        }
        priority_queue<pair<int, int>> pq;
        vector<bool> used(n + 1, false);
        int answer = 0;
        int good_answer = 0;
        for (int take = n; take >= 1; take--)
        {
            for (int type : total_freq[take])
                pq.push({good[type], type});
            while (!pq.empty() && used[pq.top().second])
                pq.pop();
            if (pq.empty())
                continue;
            auto [good_count, type] = pq.top();
            pq.pop();
            used[type] = true;
            answer += take;
            good_answer += min(take, good_count);
        }
        cout << answer << " " << good_answer << endl;
    }
    return 0;
}