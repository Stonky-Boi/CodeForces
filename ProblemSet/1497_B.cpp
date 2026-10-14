#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> freq(m, 0);
        for (int &i : a)
        {
            cin >> i;
            freq[i % m]++;
        }
        int arrays = freq[0] > 0 ? 1 : 0;
        for (int i = 1; i <= m / 2; i++)
        {
            if (freq[i] == 0 && freq[m - i] == 0)
                continue;
            arrays += max(1, abs(freq[i] - freq[m - i]));
        }
        cout << arrays << endl;
    }
    return 0;
}