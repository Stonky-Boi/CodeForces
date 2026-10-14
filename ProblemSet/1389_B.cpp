#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        long long max_score = 0;
        for (int l = 0; l <= z && l <= k / 2; l++)
        {
            int r = k - 2 * l;
            long long score = 0;
            int max_pair = 0;
            for (int i = 0; i <= r; i++)
            {
                score += a[i];
                max_pair = max(max_pair, a[i] + a[i + 1]);
            }
            score += 1ll * l * max_pair;
            max_score = max(max_score, score);
        }
        cout << max_score << endl;
    }
    return 0;
}