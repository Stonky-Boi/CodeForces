#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> freq(n + 1, 0);
        for (int &i : a)
        {
            cin >> i;
            freq[i]++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int size = freq[0], last = freq[0];
        for (int i = 1; i <= n; i++)
        {
            if (last == 0)
                break;
            int taken = min(freq[i], last - 1);
            size += taken;
            last = taken;
        }
        cout << size << endl;
    }
    return 0;
}