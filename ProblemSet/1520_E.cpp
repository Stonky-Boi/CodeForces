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
        string s;
        cin >> n >> s;
        vector<int> sheep;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
                sheep.push_back(i);
        }
        int m = sheep.size();
        if (m <= 1)
        {
            cout << 0 << endl;
            continue;
        }
        int mid = (m + 1) / 2;
        int middle = sheep[mid - 1];
        long long moves = 0;
        for (int i = 0; i < m; i++)
        {
            int final_position = middle - (mid - 1) + i;
            moves += abs(sheep[i] - final_position);
        }
        cout << moves << endl;
    }
    return 0;
}