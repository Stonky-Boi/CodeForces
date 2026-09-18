#include <iostream>
using namespace std;

int main()
{
    int distinct_colors[4] = {0}, color, horse_shoes = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> color;
        if (color != distinct_colors[0] && color != distinct_colors[1] && color != distinct_colors[2] && color != distinct_colors[3])
            distinct_colors[i] = color;
        if (distinct_colors[i] == 0)
            horse_shoes++;
    }
    cout << horse_shoes << endl;
    return 0;
}