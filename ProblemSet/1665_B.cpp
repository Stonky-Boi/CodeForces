#include <iostream>
#include <vector>
#include <map>
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
        map<int, int> freq;
        for (int &i : a)
        {
            cin >> i;
            freq[i]++;
        }
        int max_freq = 0;
        for (const auto &[_, f] : freq)
            max_freq = max(max_freq, f);
        int operations = 0;
        while (max_freq < n)
        {
            operations += 1 + min(max_freq, n - max_freq);
            max_freq += min(max_freq, n - max_freq);
        }
        cout << operations << endl;
    }
    return 0;
}