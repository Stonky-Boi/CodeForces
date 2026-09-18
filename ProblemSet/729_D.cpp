#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    vector<int> possible_cells;
    int total_ships = 0;
    int current_length = 0;
    int segment_start = -1;
    for (int i = 0; i <= n; i++)
    {
        if (i < n && s[i] == '0')
        {
            if (current_length == 0)
                segment_start = i;
            current_length++;
        }
        else
        {
            if (current_length >= b)
            {
                int ships = current_length / b;
                total_ships += ships;
                for (int j = 1; j <= ships; j++)
                    possible_cells.push_back(segment_start + j * b - 1);
            }
            current_length = 0;
        }
    }
    int shots_needed = max(0, total_ships - (a - 1));
    cout << shots_needed << endl;
    for (int i = 0; i < shots_needed; i++)
        cout << possible_cells[i] + 1 << " ";
    cout << endl;
    return 0;
}