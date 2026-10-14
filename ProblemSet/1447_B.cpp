#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        int sum = 0;
        int min_value = 100, min_count = 0;
        for (vector<int> &v : a)
        {
            for (int &i : v)
            {
                cin >> i;
                if (i < 0)
                    min_count++;
                sum += abs(i);
                min_value = min(min_value, abs(i));
            }
        }
        cout << sum - (min_count % 2 == 0 ? 0 : 2 * min_value) << endl;
    }
    return 0;
}