#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int initial_points;
    int amazing_performances = 0;
    cin >> initial_points;
    int max = initial_points, min = initial_points;
    n--;
    while (n--)
    {
        int points;
        cin >> points;
        if (points > max)
        {
            amazing_performances++;
            max = points;
        }
        if (points < min)
        {
            amazing_performances++;
            min = points;
        }
    }
    cout << amazing_performances << endl;
    return 0;
}