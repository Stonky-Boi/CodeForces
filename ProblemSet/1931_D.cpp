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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        map<pair<int, int>, int> freq;
        long long pairs = 0;
        for (int &i : a)
        {
            cin >> i;
            int rx = i % x;
            int ry = i % y;
            pairs += freq[{(x - rx) % x, ry}];
            freq[{rx, ry}]++;
        }
        cout << pairs << endl;
    }
    return 0;
}