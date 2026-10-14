#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int K = 1e6;
const int MAX_VALUE = 1e9;

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
        map<int, long long> freq;
        for (int &i : a)
        {
            cin >> i;
            freq[i]++;
        }
        long long triples = 0;
        for (const int &i : a)
            triples += (freq[i] - 1) * (freq[i] - 2); // b = 1 (identical case)
        for (const auto &[i, value] : freq)
        {
            if (i > K)
            {
                for (long long b = 2; b * i <= MAX_VALUE; b++)
                {
                    if (i % b == 0 && freq.find(i / b) != freq.end() && freq.find(i * b) != freq.end())
                        triples += freq[i / b] * freq[i * b] * value;
                }
            }
            else
            {
                for (long long b = 2; b * b <= i; b++)
                {
                    if (i % b == 0)
                    {
                        if (1ll * i * b <= MAX_VALUE && freq.find(i / b) != freq.end() && freq.find(i * b) != freq.end())
                            triples += freq[i / b] * freq[i * b] * value;
                        if (b * b != i)
                        {
                            long long x = 1ll * i * i / b;
                            if (x <= MAX_VALUE && freq.find(b) != freq.end() && freq.find(x) != freq.end())
                                triples += freq[b] * freq[x] * value;
                        }
                    }
                }
                if (i > 1 && 1ll * i * i <= MAX_VALUE && freq.find(1) != freq.end() && freq.find(1ll * i * i) != freq.end())
                    triples += freq[1] * freq[1ll * i * i] * value;
            }
        }
        cout << triples << endl;
    }
    return 0;
}