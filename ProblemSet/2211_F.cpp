#include <iostream>
#include <vector>
using namespace std;

const int MOD = 676767677;
const int MAX_N = 2000000 + 5;

long long factorial[MAX_N];
long long inverse_factorial[MAX_N];
long long inverse[MAX_N];

long long mod_pow(long long base, long long exponent)
{
    long long result = 1;
    base %= MOD;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

long long ncr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    long long result = factorial[n];
    result = (result * inverse_factorial[r]) % MOD;
    result = (result * inverse_factorial[n - r]) % MOD;
    return result;
}

long long stars_and_bars(int K, int S)
{
    return ncr(S + K - 1, K - 1);
}

int n, m;
long long answer;

void dfs(int left, int right, int depth)
{
    if (left > right)
        return;
    int mid = (left + right) / 2;
    int left_prev = left - 1;
    int right_next = right + 1;
    long long total = stars_and_bars(n + 1, m);
    answer = (answer + total * depth) % MOD;
    if (left_prev != -1)
    {
        int length = mid - left_prev;
        long long bad = stars_and_bars(n + 1 - length, m);
        answer = (answer - bad * depth) % MOD;
        if (answer < 0)
            answer += MOD;
    }
    if (right_next != n)
    {
        int length = right_next - mid;
        long long bad = stars_and_bars(n + 1 - length, m);
        answer = (answer - bad * depth) % MOD;
        if (answer < 0)
            answer += MOD;
    }
    if (left_prev != -1 && right_next != n)
    {
        int length = right_next - left_prev;
        long long add = stars_and_bars(n + 1 - length, m);
        answer = (answer + add * depth) % MOD;
        answer %= MOD;
    }
    dfs(left, mid - 1, depth + 1);
    dfs(mid + 1, right, depth + 1);
}

int main()
{
    factorial[0] = 1;
    for (int i = 1; i < MAX_N; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;
    inverse[MAX_N - 1] = mod_pow(factorial[MAX_N - 1], MOD - 2);
    inverse_factorial[MAX_N - 1] = inverse[MAX_N - 1];
    for (int i = MAX_N - 1; i > 0; i--)
        inverse_factorial[i - 1] = (inverse_factorial[i] * i) % MOD;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        m--;
        answer = 0;
        dfs(0, n - 1, 1);
        cout << answer << endl;
    }
    return 0;
}