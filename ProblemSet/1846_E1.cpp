#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MAXN = 1e6;
    vector<bool> possible(MAXN + 1, false);
    for (long long k = 2; 1 + k + k * k <= MAXN; k++)
    {
        long long sum = 1 + k + k * k;
        long long power = k * k;
        while (sum <= MAXN)
        {
            possible[sum] = true;
            power *= k;
            sum += power;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (possible[n] ? "YES" : "NO") << endl;
    }
    return 0;
}