#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> indices;

int get_index(long long x)
{
    return int(lower_bound(indices.begin(), indices.end(), x) - indices.begin());
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<tuple<long long, long long, int>> updates(N);
    vector<pair<long long, long long>> queries(Q);
    for (auto &[l, r, v] : updates)
    {
        cin >> l >> r >> v;
        indices.push_back(l);
        indices.push_back(r);
    }
    for (auto &[l, r] : queries)
    {
        cin >> l >> r;
        indices.push_back(l);
        indices.push_back(r);
    }
    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());
    int M = indices.size();
    vector<long long> difference(M + 1, 0);
    for (auto [l, r, v] : updates)
    {
        int L = get_index(l);
        int R = get_index(r);
        difference[L] += v;
        difference[R] -= v;
    }
    vector<long long> value(M, 0);
    value[0] = difference[0];
    for (int i = 1; i < M; i++)
        value[i] = value[i - 1] + difference[i];
    vector<long long> prefix(M + 1, 0);
    for (int i = 0; i < M - 1; i++)
    {
        long long length = indices[i + 1] - indices[i];
        prefix[i + 1] = prefix[i] + value[i] * length;
    }
    for (auto [l, r] : queries)
    {
        int L = get_index(l);
        int R = get_index(r);
        cout << prefix[R] - prefix[L] << endl;
    }
    return 0;
}