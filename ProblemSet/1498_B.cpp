#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, W;
        cin >> n >> W;
        vector<int> w(n);
        vector<int> freq(20, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
            int b = log2(w[i]);
            freq[b]++;
        }
        int height = 0;
        while (n > 0)
        {
            height++;
            int remaining = W;
            for (int b = 19; b >= 0; b--)
            {
                int width = 1 << b;
                int take = min(freq[b], remaining / width);
                freq[b] -= take;
                n -= take;
                remaining -= take * width;
            }
        }
        cout << height << endl;
    }
    return 0;
}