#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int p[n], position[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            position[p[i] - 1] = i;
        }
        string s;
        cin >> s;
        int difference[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            int l = min(i, position[i]);
            int r = max(i, position[i]);
            difference[l]++;
            difference[r]--;
        }
        int coverage[n] = {0};
        int current = 0;
        for (int i = 0; i < n; i++)
        {
            current += difference[i];
            coverage[i] = current;
        }
        set<int> bad_indices;
        for (int i = 0; i < n - 1; i++)
            if (s[i] == 'L' && s[i + 1] == 'R' && coverage[i] > 0)
                bad_indices.insert(i);
        while (q--)
        {
            int i;
            cin >> i;
            i--;
            int index_1 = i - 1;
            int index_2 = i;
            if (index_1 >= 0 && index_1 < n - 1 && coverage[index_1] > 0)
            {
                if (s[index_1] == 'L' && s[index_1 + 1] == 'R')
                    bad_indices.insert(index_1);
                else
                    bad_indices.erase(index_1);
            }
            if (index_2 >= 0 && index_2 < n - 1 && coverage[index_2] > 0)
            {
                if (s[index_2] == 'L' && s[index_2 + 1] == 'R')
                    bad_indices.insert(index_2);
                else
                    bad_indices.erase(index_2);
            }
            if (s[i] == 'L')
                s[i] = 'R';
            else
                s[i] = 'L';
            if (index_1 >= 0 && index_1 < n - 1 && coverage[index_1] > 0)
            {
                if (s[index_1] == 'L' && s[index_1 + 1] == 'R')
                    bad_indices.insert(index_1);
                else
                    bad_indices.erase(index_1);
            }
            if (index_2 >= 0 && index_2 < n - 1 && coverage[index_2] > 0)
            {
                if (s[index_2] == 'L' && s[index_2 + 1] == 'R')
                    bad_indices.insert(index_2);
                else
                    bad_indices.erase(index_2);
            }
            if (bad_indices.empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}