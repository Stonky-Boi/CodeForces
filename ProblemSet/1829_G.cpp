#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MAX_N = 1e6 + 1, SIZE = 1500;
    vector<long long> sum(MAX_N, 0);
    vector<vector<long long>> prefix(SIZE, vector<long long>(SIZE, 0));
    int curr = 1;
    for (int d = 1; d < SIZE && curr <= 1e6; d++)
    {
        for (int r = d - 1; r >= 1 && curr <= 1e6; r--)
        {
            int c = d - r;
            prefix[r][c] = prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1] + 1ll * curr * curr;
            sum[curr] = prefix[r][c];
            curr++;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << sum[n] << endl;
    }
    return 0;
}