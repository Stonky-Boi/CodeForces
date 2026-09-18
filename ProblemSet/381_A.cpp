#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], sereja_points = 0, dima_points = 0;
    int left_position = 0, right_position = n - 1;
    bool sereja_turn = true;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (left_position <= right_position)
    {
        if (a[left_position] > a[right_position])
        {
            if (sereja_turn)
                sereja_points += a[left_position];
            else
                dima_points += a[left_position];
            left_position++;
        }
        else
        {
            if (sereja_turn)
                sereja_points += a[right_position];
            else
                dima_points += a[right_position];
            right_position--;
        }
        sereja_turn = !sereja_turn;
    }
    cout << sereja_points << " " << dima_points << endl;
    return 0;
}