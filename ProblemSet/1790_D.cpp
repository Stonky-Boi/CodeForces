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
        int k = 0;
        for (const auto &[i, f] : freq)
            k += max(0, freq[i] - freq[i - 1]);
        cout << k << endl;
    }
    return 0;
}