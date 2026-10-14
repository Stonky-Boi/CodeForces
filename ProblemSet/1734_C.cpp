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
        string s;
        cin >> s;
        vector<bool> removed(n + 1, false);
        long long cost = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                if (s[j - 1] == '1')
                    break;
                if (!removed[j])
                {
                    removed[j] = true;
                    cost += i;
                }
            }
        }
        cout << cost << endl;
    }
    return 0;
}