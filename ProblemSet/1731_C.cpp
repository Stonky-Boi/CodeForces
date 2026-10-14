#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<int> squares;
        for (int i = 0; i * i < 2 * n; i++)
            squares.push_back(i * i);
        vector<int> freq(2 * n + 1, 0);
        freq[0] = 1;
        int prefix_xor = 0;
        long long odd = 0;
        for (const int &i : a)
        {
            prefix_xor ^= i;
            for (const int &s : squares)
            {
                int need = prefix_xor ^ s;
                if (need <= 2 * n)
                    odd += freq[need];
            }
            freq[prefix_xor]++;
        }
        long long total = 1ll * n * (n + 1) / 2;
        cout << total - odd << endl;
    }
    return 0;
}