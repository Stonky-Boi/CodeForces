#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_A = 1e6;
vector<long long> freq(MAX_A + 1, 0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int max_value = 0;
        for (int &i : a)
        {
            cin >> i;
            freq[i]++;
            max_value = max(max_value, i);
        }
        long long triples = 0;
        for (const int &i : a)
        {
            triples += (freq[i] - 1) * (freq[i] - 2); // b = 1 (identical case)
            for (int b = 2; 1ll * i * b * b <= max_value; b++)
                triples += freq[i * b] * freq[i * b * b];
        }
        for (const int &i : a)
            freq[i]--;
        cout << triples << endl;
    }
    return 0;
}