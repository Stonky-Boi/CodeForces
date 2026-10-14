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
        vector<int> p(n);
        for (int &i : p)
        {
            cin >> i;
            i--;
        }
        vector<int> cycle_id(n, -1);
        int cycles = 0;
        for (int i = 0; i < n; i++)
        {
            if (cycle_id[i] != -1)
                continue;
            int curr = i;
            while (cycle_id[curr] == -1)
            {
                cycle_id[curr] = cycles;
                curr = p[curr];
            }
            cycles++;
        }
        int operations = n;
        for (int i = 0; i < n - 1; i++)
        {
            int candidate = n - cycles + (cycle_id[i] == cycle_id[i + 1] ? -1 : 1);
            operations = min(operations, candidate);
        }
        cout << operations << endl;
    }
    return 0;
}