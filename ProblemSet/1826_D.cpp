#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        long long int b[n];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        long long int prefix[n], suffix[n];
        prefix[0] = b[0] + 0;
        for (int i = 1; i < n; i++)
            prefix[i] = max(prefix[i - 1], b[i] + i);
        suffix[n - 1] = b[n - 1] - (n - 1);
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = max(suffix[i + 1], b[i] - i);
        int max_score = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int score = b[i] + prefix[i - 1] + suffix[i + 1];
            max_score = max(max_score, score);
        }
        cout << max_score << endl;
    }
    return 0;
}
