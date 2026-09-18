#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<string> grid(8);
        for (int i = 0; i < 8; i++)
            getline(cin, grid[i]);
        int column = -1;
        for (int i = 0; i < 8 && column == -1; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (isalpha(grid[i][j]))
                {
                    column = j;
                    break;
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (isalpha(grid[i][column]))
                cout << grid[i][column];
        }
        cout << endl;
    }
    return 0;
}