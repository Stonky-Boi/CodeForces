#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> sequences;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        int l = 0, r = (int)sequences.size();
        while (l < r)
        {
            int m = (l + r) / 2;
            if (sequences[m].back() < a)
                r = m;
            else
                l = m + 1;
        }
        if (l == (int)sequences.size())
            sequences.push_back({a});
        else
            sequences[l].push_back(a);
    }
    for (auto &seq : sequences)
    {
        for (auto x : seq)
            cout << x << " ";
        cout << endl;
    }
}