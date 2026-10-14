#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vector<int> curr(m + 1, 0), next(m + 1, 0);
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        next[0] = 0;
        for (int j = 1; j <= m; j++)
        {
            next[j] = max(curr[j], next[j - 1]) - 1;
            if (a[i - 1] == b[j - 1])
                next[j] = max(next[j], curr[j - 1] + 2);
            next[j] = max(next[j], 0);
            s = max(s, next[j]);
        }
        curr.swap(next);
    }
    cout << s << endl;
    return 0;
}