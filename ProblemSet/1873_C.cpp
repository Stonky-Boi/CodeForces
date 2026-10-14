#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<string> grid(10);
        for (string &i : grid)
            cin >> i;
        int points = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = i; j < 10 - i; j++)
            {
                for (int k = i; k < 10 - i; k++)
                {
                    if (grid[j][k] == 'X')
                        points++;
                }
            }
        }
        cout << points << endl;
    }
    return 0;
}