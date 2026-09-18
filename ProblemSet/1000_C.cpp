#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> points;
    vector<pair<long long, long long>> segments(n);
    for (auto &[l, r] : segments)
    {
        cin >> l >> r;
        points.push_back(l);
        points.push_back(r + 1);
    }
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    int M = points.size();
    vector<long long> difference(M + 1, 0);
    for (auto [l, r] : segments)
    {
        int L = lower_bound(points.begin(), points.end(), l) - points.begin();
        int R = lower_bound(points.begin(), points.end(), r + 1) - points.begin();
        difference[L] += 1;
        difference[R] -= 1;
    }
    vector<long long> coverage(M, 0);
    coverage[0] = difference[0];
    for (int i = 1; i < M; i++)
        coverage[i] = coverage[i - 1] + difference[i];
    vector<long long> cnt(n + 1, 0);
    for (int i = 0; i < M - 1; i++)
    {
        long long length = points[i + 1] - points[i];
        if (coverage[i] > 0)
            cnt[coverage[i]] += length;
    }
    for (int i = 1; i <= n; i++)
        cout << cnt[i] << " ";
    cout << endl;
    return 0;
}