#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        long long sum = 0;
        int H = 0, W = 0;
        for (auto &[x, y] : a)
        {
            cin >> x >> y;
            sum += 1ll * x * y;
            H = max(H, x);
            W = max(W, y);
        }
        set<pair<long long, long long>> candidates;
        if (sum % H == 0)
            candidates.insert({H, sum / H});
        if (sum % W == 0)
            candidates.insert({sum / W, W});
        vector<pair<long long, long long>> rectangles;
        for (const auto &[h, w] : candidates)
        {
            set<pair<long long, int>> set_h, set_w;
            for (int i = 0; i < n; i++)
            {
                set_h.insert({a[i].first, i});
                set_w.insert({a[i].second, i});
            }
            long long curr_h = h;
            long long curr_w = w;
            int remaining = n;
            while (remaining > 1)
            {
                auto it_h = set_h.lower_bound({curr_h, -1});
                auto it_w = set_w.lower_bound({curr_w, -1});
                if (it_h != set_h.end() && it_h->first == curr_h)
                {
                    int i = it_h->second;
                    set_h.erase(it_h);
                    set_w.erase({a[i].second, i});
                    curr_w -= a[i].second;
                }
                else if (it_w != set_w.end() && it_w->first == curr_w)
                {
                    int i = it_w->second;
                    set_w.erase(it_w);
                    set_h.erase({a[i].first, i});
                    curr_h -= a[i].first;
                }
                else
                    break;
                remaining--;
            }
            if (remaining == 1)
            {
                int i = set_h.begin()->second;
                if (a[i].first == curr_h && a[i].second == curr_w)
                    rectangles.push_back({h, w});
            }
        }
        cout << rectangles.size() << endl;
        for (const auto &[h, w] : rectangles)
            cout << h << " " << w << endl;
    }
    return 0;
}