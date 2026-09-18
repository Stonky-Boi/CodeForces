#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        const int max_size = 1000;
        vector<vector<long long>> prefix(max_size + 1, vector<long long>(max_size + 1));
        for (int i = 0; i < n; i++)
        {
            int h, w;
            cin >> h >> w;
            prefix[h][w] += 1ll * h * w;
        }
        for (int h = 1; h <= max_size; h++)
            for (int w = 1; w <= max_size; w++)
                prefix[h][w] += prefix[h - 1][w] + prefix[h][w - 1] - prefix[h - 1][w - 1];
        while (q--)
        {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            hs++;
            ws++;
            hb--;
            wb--;
            long long area_sum = prefix[hb][wb] - prefix[hs - 1][wb] - prefix[hb][ws - 1] + prefix[hs - 1][ws - 1];
            cout << area_sum << endl;
        }
    }
    return 0;
}