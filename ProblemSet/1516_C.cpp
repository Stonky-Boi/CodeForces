#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int &i : a)
    {
        cin >> i;
        sum += i;
    }
    if (sum % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (const int &i : a)
    {
        for (int s = target; s >= i; s--)
            dp[s] = dp[s] || dp[s - i];
    }
    if (!dp[target])
    {
        cout << 0 << endl;
        return 0;
    }
    int index = 0;
    int minimum = 1e6;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int count = 0;
        while (x % 2 == 0)
        {
            x /= 2;
            count++;
        }
        if (count < minimum)
        {
            minimum = count;
            index = i;
        }
    }
    cout << 1 << endl;
    cout << index + 1 << endl;
    return 0;
}