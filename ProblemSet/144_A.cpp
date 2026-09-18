#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int max_height = 0, min_height = 100, position_min, position_max;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > max_height)
        {
            max_height = a[i];
            position_max = i;
        }
        if (a[i] <= min_height)
        {
            min_height = a[i];
            position_min = i;
        }
    }
    int moves = position_max + (n - position_min - 1);
    if (position_max > position_min)
        moves--;
    cout << moves << endl;
    return 0;
}