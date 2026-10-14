#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <chrono>
using namespace std;

int main()
{
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        map<int, long long> hash;
        for (int &i : a)
        {
            cin >> i;
            if (hash.find(i) == hash.end())
                hash[i] = rng();
        }
        vector<long long> prefix_xor(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix_xor[i + 1] = prefix_xor[i] ^ hash[a[i]];
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << (prefix_xor[r] == prefix_xor[l - 1] ? "YES" : "NO") << endl;
        }
    }
    return 0;
}