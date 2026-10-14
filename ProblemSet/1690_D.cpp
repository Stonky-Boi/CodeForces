#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int max_cells = 0, curr_cells = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
                curr_cells++;
            if (i >= k && s[i - k] == 'B')
                curr_cells--;
            max_cells = max(max_cells, curr_cells);
        }
        cout << k - max_cells << endl;
    }
    return 0;
}