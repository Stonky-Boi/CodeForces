#include <iostream>
using namespace std;

int main()
{
    int x_coordinate, y_coordinate;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int n;
            cin >> n;
            if (n == 1)
            {
                x_coordinate = i + 1;
                y_coordinate = j + 1;
            }
        }
    }
    int moves = abs(x_coordinate - 3) + abs(y_coordinate - 3);
    cout << moves << endl;
    return 0;
}