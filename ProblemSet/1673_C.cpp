#include <iostream>
#include <vector>
using namespace std;

bool palindrome(int x)
{
    int original = x;
    int reversed = 0;
    while (x > 0)
    {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return original == reversed;
}

int main()
{
    int MOD = 1e9 + 7, MAX = 4e4;
    vector<int> palindromes;
    for (int i = 1; i <= MAX; i++)
    {
        if (palindrome(i))
            palindromes.push_back(i);
    }
    vector<int> dp(MAX + 1, 0); // dp[i] = number of ways to make sum i with all palindromes
    dp[0] = 1;
    for (const int &i : palindromes)
    {
        for (int j = i; j <= MAX; j++)
            dp[j] = (dp[j] + dp[j - i]) % MOD;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}