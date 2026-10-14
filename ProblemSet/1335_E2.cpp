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
        vector<vector<int>> prefix(201, vector<int>(n + 1, 0));
        vector<vector<int>> position(201);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            position[a[i]].push_back(i);
            for (int j = 1; j <= 200; j++)
                prefix[j][i + 1] = prefix[j][i];
            prefix[a[i]][i + 1]++;
        }
        int length = 0;
        for (int i = 1; i <= 200; i++)
        {
            int size = position[i].size();
            for (int j = 0; j <= size / 2; j++)
            {
                int l = 0, r = n - 1;
                if (j > 0)
                {
                    l = position[i][j - 1] + 1;
                    r = position[i][size - j] - 1;
                }
                int max_value = 0;
                for (int k = 1; k <= 200; k++)
                {
                    int count = prefix[k][r + 1] - prefix[k][l];
                    max_value = max(max_value, count);
                }
                length = max(length, 2 * j + max_value);
            }
        }
        cout << length << endl;
    }
    return 0;
}