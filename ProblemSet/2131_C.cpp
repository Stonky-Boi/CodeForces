#include <iostream>
#include <map>
using namespace std;

long long canonical(long long x, long long k)
{
    long long r = x % k;
    return min(r, (k - r) % k);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        long long S[n], T[n];
        for (int i = 0; i < n; i++)
            cin >> S[i];
        for (int i = 0; i < n; i++)
            cin >> T[i];
        if (k == 0)
        {
            sort(S, S + n);
            sort(T, T + n);
            cout << (S == T ? "YES" : "NO") << endl;
            continue;
        }
        map<long long, int> freq_S, freq_T;
        for (auto x : S)
            freq_S[canonical(x, k)]++;
        for (auto x : T)
            freq_T[canonical(x, k)]++;
        cout << (freq_S == freq_T ? "YES" : "NO") << endl;
    }
    return 0;
}